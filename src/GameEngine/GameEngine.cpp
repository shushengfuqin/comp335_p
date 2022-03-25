#include "GameEngine.h"
#include <iostream>
#include <regex>

/**
 * Why input int instead of string.
 * The user input and define action is using an switch case statement. It is more clear and easy then if statements.
 * However, in cpp, the switch case evaluate only int.
 * It is possible to use enum for the different transition cmd. However the cmd are overlapping with the state.
 * Which create confusion in the convention.
 */

/**
 * userInput will save the cmd of the user.
 */
int userInput;
regex loadRegex ("loadmap\\s.+");
regex playerRegex("addplayer\\s.+");


GameEng::GameEng() {
    cmdProc = new CommandProcessor();
    playerList = new vector<Player*>();
}

GameEng::GameEng(CommandProcessor * cp) {
    cmdProc = cp;
    playerList = new vector<Player*>();
}

GameEng::GameEng(FileLineReader *flr) {
    cmdProc = new FileCommandProcessorAdapter(flr);
    playerList = new vector<Player*>();
}

GameEng::~GameEng() = default;

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command loadmap,
 * The system will keep ask the use to input an valid command.
 * @return the command loadmap
 */

string GameEng::startFunc()
{
    cout << "this is the start state\n";
    cout << "1 - loadmap <mapfile>\n";
    cmdProc->getCommand();
    for (;;)
    {
        cmdInput = cmdProc->validate(getState());

        if(regex_match (cmdInput, loadRegex)) {
            string mapName = cmdInput.substr(cmdInput.find(" ") + 1);
            LoadMap(mapName);

            cout << "Moving to the next state\n";
            Notify(this);

            return "loadmap";
        }
        else{
            cout << "Error: Please enter an valid command\n";
            cmdProc->getCommand();
            continue;
        }
    }

}

//
void GameEng::LoadMap(string name){
    pMapLoader = new MapLoader("../canada/"+name+".map");
    generatedMap = pMapLoader->generateMap();

    for (int i = 0; i < generatedMap->getSize(); ++i) {
        generatedMap->printTerritoryBorders(i);
    }
}

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd loadmap.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "validatemap"
 */
string GameEng::maploadedFunc()
{
    cout << "this is the map loaded state\n";
    cout << "1 - loadmap <mapfile>\n";
    cout << "2 - validatemap\n";
    cmdProc->getCommand();

    for (;;)
    {
        cmdInput = cmdProc->validate(getState());

        if(regex_match (cmdInput, loadRegex)){
            // *** LOAD MAP HERE ***
            string mapName = cmdInput.substr(cmdInput.find(" ") + 1);
            LoadMap(mapName);
            cout << "map loaded again\n";
            cout << "1 - loadmap <mapfile>\n";
            cout << "2 - validatemap\n";
            cmdProc->getCommand();
            continue;
        }
        else if(cmdInput == "validatemap"){
            // *** VALIDATE MAP HERE ***
            if (generatedMap->validate()) {
                cout << endl << "---MAP GENERATION VALID---" << endl;
            } else {
                cout << endl << "---MAP GENERATION INVALID---" << endl;
                return "invalidmap";
            }

            cout << "Moving to next state\n";
            //Notify(this);
            return "validatemap";
        }
        else{
            cout << "Error: Please enter a valid input\n";
            cmdProc->getCommand();
            continue;
        }
    }
}

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command addplayer,
 * The system will keep ask the use to input an valid command.
 * @return "addplayer"
 */
string GameEng::mapvalidatedFunc()
{
    string nextState;
    cout << "this is the map validated state\n";
    cout << "1 - addplayer <playername> \n";
    cmdProc->getCommand();

    for (;;) {
        cmdInput = cmdProc->validate(getState());

        if(regex_match (cmdInput, playerRegex)){
            // *** ADD PLAYER HERE ***
            string playerName = cmdInput.substr(cmdInput.find(" ") + 1);
            Player *player = new Player(playerName);
            player->setPlayerId(++playerCount);
            playerList->push_back(player);
            cout << "Added player: " << playerName << endl;

            cout << "Moving to the next state\n";
            Notify(this);
            return "addplayer";
        }
        else{
            cout << "Error: Please enter an valid command\n";
            cmdProc->getCommand();
            Notify(this);
            continue;
        }
    }
}

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd addplayer.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "assigncountries"
 */
string GameEng::playeraddedFunc()
{
    cout << "this is the player added state\n";
    cout << "1 - addplayer <playername> \n";
    cout << "2 - gamestart\n";
    cmdProc->getCommand();
    for (;;)
    {
        cmdInput = cmdProc->validate(getState());
        if(regex_match (cmdInput, playerRegex)){
            // *** ADD PLAYER HERE ***
            string playerName = cmdInput.substr(cmdInput.find(" ") + 1);
            Player *player = new Player(playerName);
            player->setPlayerId(++playerCount);
            playerList->push_back(player);
            cout << "Added player: " << playerName << endl;
            cout << "this is the player added state\n";
            cout << "1 - addplayer <playername> \n";
            cout << "2 - gamestart\n";
            cmdProc->getCommand();
            continue;
        }
        else if(cmdInput == "gamestart"){
            cout << "Moving to next state\n";
            Notify(this);

            // *** START GAME HERE ***
            return "assigncountries";
        }
        else{
            cout << "Error: Please enter a valid input\n";
            cmdProc->getCommand();
            continue;
        }
    }
}

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command addplayer,
 * The system will keep ask the use to input an valid command.
 * @return "issueorder"
 */
string GameEng::assignreinforcementFunc()
{
    cout << "this is the assign reinforcement state\n";
    cout << "What would you like to do\n";
    cout << "1 - issue order\n";
    cout << "Please chose action by typing the corresponding number\n";
    cin >> userInput;
    while (userInput != 1)
    {
        cout << "Error: Please enter an valid command\n";
        cin >> userInput;
    }
    cout << "Moving to the next state\n";
    return "issueorder";
}

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd issueorder.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "endissuorders"
 */
string GameEng::issueordersFunc()
{
    cout << "this is the issue order state\n";
    cout << "What would you like to do\n";
    cout << "1 - issue order\n";
    cout << "2 - end issue orders\n";
    cout << "Please chose action by typing the corresponding number\n";
    cin >> userInput;
    for (;;)
    {
        switch (userInput)
        {
        case 1:
            cout << "issue order again\n";
            cout << "What would you like to do\n";
            cout << "1 - issue order\n";
            cout << "2 - end issue orders\n";
            cout << "Please chose action by typing the corresponding number\n";
            cin >> userInput;
            continue;
        case 2:
            cout << "Moving to next state\n";
            return "endissuorders";
        default:
            cout << "Error: Please enter a valid input\n";
            cin >> userInput;
        }
    }
}

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd execute order.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "endexecorders" or "win"
 */
string GameEng::executeordersFunc()
{
    cout << "this is the execute order state\n";
    cout << "What would you like to do\n";
    cout << "1 - execute order\n";
    cout << "2 - end execute order\n";
    cout << "3 - win\n";
    cout << "Please chose action by typing the corresponding number\n";
    cin >> userInput;
    for (;;)
    {
        switch (userInput)
        {
        case 1:
            cout << "execute order again\n";
            cout << "What would you like to do\n";
            cout << "1 - execute order\n";
            cout << "2 - end execute orders\n";
            cout << "3 - win\n";
            cout << "Please chose action by typing the corresponding number\n";
            cin >> userInput;
            continue;
        case 2:
            cout << "Moving to assign reinforcement state\n";
            return "endexecorders";
        case 3:
            cout << "Moving to win state\n";
            return "win";
        default:
            cout << "Error: Please enter a valid input\n";
            cin >> userInput;
        }
    }
}

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep choosing an invalid cmd
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "end" or "play"
 */
string GameEng::winFunc()
{
    cout << "this is the win state\n";
    cout << "1 - replay\n";
    cout << "2 - quit\n";
    cmdProc->getCommand();
    for (;;)
    {
        userCmd = cmdProc->validate(getState());

        if(userCmd == "replay"){
            cout << "Moving to next state\n";
            return "replay";
        }
        else if(userCmd == "quit"){
            cout << "Thank you for playing. See you next time\n";
            return "quit";
        }
        else{
            cout << "Error: Please enter a valid input\n";
            cmdProc->getCommand();
            continue;
        }
    }
}

void GameEng::Transition(){
    Notify(this);
}

void GameEng::startUpPhase() {
    // Clear player list
    playerList->clear();

    // Continue until start up phase is complete
    while(getState() != win && getState() != assignreignforcement){
        switch (getState()) {
            case start:
                if (startFunc() == "loadmap") {
                    setState(maploaded);
                }
            case maploaded:
                if (maploadedFunc() == "validatemap") {
                    setState(mapvalidated);
                }
            case mapvalidated:
                if (mapvalidatedFunc() == "addplayer") {
                    setState(playeradded);
                }
            case playeradded:
                if (playeraddedFunc() == "assigncountries") {
                    setState(win);
                }
            default:
                break;
        }
    }

    // Clean up
    delete (pMapLoader);
    pMapLoader = NULL;

}

void GameEng::mainGameLoop(){
    //while the amount of player is not 1 the main game loop will keep looping.
    while(playerCount != 1){
        cout << "------------ TURN : " << turnNum << " ------------\n";
        // call the reinforcementphase
        if(turnNum != 1){
            reinforcementPhase();
        }
        issueOrdersPhase();
        executeOrdersPhase();
        turnNum++;
    }

}

void GameEng::reinforcementPhase() {
    cout << "------------ Reinforcement Phase ------------\n";
    //check if the player has still army
    for(auto &i: *playerList){
        i->calculateBonus(generatedMap);
    }
}

void GameEng::issueOrdersPhase() {
    cout << "------------ Issue Orders Phase ------------\n";
    // count if there are still player not done in deploying
    int exit_Count = 0;
    // all player in deploy mode
    while (exit_Count < playerCount) {
        for (auto &i: *playerList) {
            if (i->getArmyNum() != 0) {
                // current player, which territory and amount of armies.
                // the territory is an object
                // army int
                // cout << i->getPlayerId() << endl;
                // cout << i->getArmyNum()<< endl;

                cout << "------------ Player : " << i->getPlayerName() << " ------------" << endl;
                // x the amount of player want to deploy
                int x;
                // y the id for the territory want to deploy army to.
                int y;
                cout << "You have " << i->getArmyNum() << " army left\n";
                cout << "Where would you like to deploy for army\n";
                cin >> y;
                cout << "How many army do you wish to deploy" << endl;
                cin >> x;
                i->removeArmyNum(x);
                // Deploy *deploy = new Deploy(i,);
                // i->issueOrders();
                cout << "current army num " << i->getArmyNum() << endl;
                if (i->getArmyNum() == 0) {
                    exit_Count++;
                }
            }
        }
    }

    // issue order
    int exit_Count2 = 0;
    int x[playerCount];
    while(exit_Count2 < playerCount){
        for(auto &i: *playerList){
            cout << "------------ Player : " << i->getPlayerName() << " ------------" << endl;
            if(x[i->getPlayerId()] !=1){
                string command;
                string done;
                bool correct = true;
                while (correct){
                    cout << "what would you like to do\n";
                    cin >> command;
                    if(command == "Advance"){
                        cout << "you chose advance\n";
//                    Advance *advance = new Advance(i,)
                        correct = false;
                    } else if (command == "Bomb") {
                        cout << "you chose bomb\n";
                        correct = false;
                    } else if (command == "Blockade") {
                        cout << "you chose blockade\n";
                        correct = false;
                    } else if (command == "Airlift") {
                        cout << "you chose airlift\n";
                        correct = false;
                    } else if (command == "Negotiate") {
                        cout << "you chose negotiate\n";
                        correct = false;
                    } else {
                        cout << "please enter an available order\n";
                        continue;
                    }
                }


                cout << "are you done with issue Order? If yes type Y. Else type anything\n";
                cin >> done;
                if(done == "Y"){
                    exit_Count2++;
                    x[i->getPlayerId()] = 1;
                }
            }
        }
    }
}

void GameEng::executeOrdersPhase() {
    cout << "------------ Execute Orders Phase ------------\n";
    int exit_count3 = 0;
    while(exit_count3 < playerCount){
        for(auto &i: *playerList){
         //check if the orderlist is empty
         if(i->get)
        }
    }
}

string GameEng::stringToLog() {
    return "Game Engine: " + userCmd;
}
