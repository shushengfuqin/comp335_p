#include "GameEngine.h"
#include <iostream>
#include <regex>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <random>

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
    gameDeck = new Deck(60);
}

GameEng::GameEng(CommandProcessor * cp) {
    cmdProc = cp;
    playerList = new vector<Player*>();
    gameDeck = new Deck(60);
}

GameEng::GameEng(FileLineReader *flr) {
    cmdProc = new FileCommandProcessorAdapter(flr);
    playerList = new vector<Player*>();
    gameDeck = new Deck(60);
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
            string mapName = cmdInput.substr(cmdInput.find(' ') + 1);
            bool loaded = LoadMap(mapName);

            if(loaded){
                cout << "Moving to the next state\n";
                Notify(this);

                return "loadmap";
            }
            else{
                cout << "this is the start state\n";
                cout << "1 - loadmap <mapfile>\n";
                cmdProc->getCommand();
                continue;
            }
        }
        else{
            cout << "Error: Please enter an valid command\n";
            cmdProc->getCommand();
            continue;
        }
    }

}

bool GameEng::LoadMap(const string& name){
    pMapLoader = new MapLoader("../"+name+"/"+name+".map");

    // Failed to load filename
    if(!pMapLoader->success)
        return false;

    generatedMap = pMapLoader->generateMap();

    for (int i = 0; i < generatedMap->getSize(); ++i) {
        generatedMap->printTerritoryBorders(i);
    }

    return true;
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
            string mapName = cmdInput.substr(cmdInput.find(' ') + 1);
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

    for (;;) {
        cout << "this is the map validated state\n";
        cout << "1 - addplayer <playername> \n";
        cmdProc->getCommand();
        cmdInput = cmdProc->validate(getState());

        if(regex_match (cmdInput, playerRegex)){
            // *** ADD PLAYER HERE ***
            string playerName = cmdInput.substr(cmdInput.find(' ') + 1);
            auto *player = new Player(playerName);
            player->setPlayerId(++playerCount);
            playerList->push_back(player);
            cout << "Added player: " << playerName << endl;

            if(playerCount > 1) {
                cout << "Moving to the next state\n";
                Notify(this);
                return "addplayer";
            }
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
            if(playerCount >= 6){
                cout << "Max player limit reached. Unable to add new player." << endl;
            }
            else{
                string playerName = cmdInput.substr(cmdInput.find(' ') + 1);
                auto *player = new Player(playerName);
                player->setPlayerId(++playerCount);
                playerList->push_back(player);
                cout << "Added player: " << playerName << endl;
            }
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
            // Fairly distributing the territories among all players
            neutral = new Player("N/A");
            generatedMap->assignTerritoriesToPlayers(*playerList);
            generatedMap->assignTerritoriesToNeutralPlayer(neutral, *playerList);

            // Randomly determine the order of play of the players in the game
            auto rng = std::default_random_engine {};
            shuffle(playerList->begin(), playerList->end(), rng);

            // Each player to draw 2 cards each from the deck
            for(int i = 0; i < playerCount; i++){
                Player *p = playerList->at(i);
                gameDeck->draw(*p->getHand());
                gameDeck->draw(*p->getHand());
            }

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
//    delete (pMapLoader);
//    pMapLoader = NULL;

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

void GameEng::reinforcementPhase() const {
    cout << "------------ Reinforcement Phase ------------\n";
    //check if the player has still army
    for(auto &i: *playerList){
        cout << "------------ Player : " << i->getPlayerName() << " ------------\n";
        i->calculateArmy(generatedMap);
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
                cout << "------------ Player : " << i->getPlayerName() << " ------------" << endl;
                // x the amount of player want to deploy
                int x;
                // y the id for the territory want to deploy army to.
                int y;
                cout << "You have " << i->getArmyNum() << " army left\n";
                cout << "List of territory that you control\n";
                auto territory = i->getTerritoryList();
                for(auto &t : *territory){
                    cout << "Territory ID: " << t->getTerritoryId() << " Territory Name : " << t->getName() << endl;
                }
                cout << "Where would you like to deploy for army. Chose by territory Id\n";
                cin >> y;
                cout << "How many army do you wish to deploy" << endl;
                cin >> x;
                while(x > i->getArmyNum()){
                    cout << "You don't have enought amry. Please enter again.\n";
                    cin >> x;
                }
                i->removeArmyNum(x);
                for(auto &e : *territory){
                    if(e->getTerritoryId() == y){
                        cout << "This is the territory you chose: " << y << endl;
                        auto *deploy = new Deploy(i,e,x);
                        i->issueOrders(deploy);
                    }
                }
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
    for(int i = 0; i < playerCount; i++){
        x[i] = 0;
    }
    while(exit_Count2 < playerCount){
        for(auto &i: *playerList){
            cout << "------------ Player : " << i->getPlayerName() << " ------------" << endl;
            if(x[i->getPlayerId() - 1] !=1){
                string command;
                string done;
                bool correct = true;
                while (correct){
                    cout << "what would you like to do\n";
                    cout << "Here is the list of orders\nAdvance\nBomb\nBlockade\nAirlift\nNegotiate\n";
                    cin >> command;
                    if(command == "Advance"){
                        cout << "you chose advance\n";
                        // Advance need player, source T, target T, army num
                        // All your t
                        int st;
                        int tt;
                        int armyNum;
                        auto territory = i->getTerritoryList();
                        cout << "Your territory\n";
                        for(auto &pT: *territory){
                            cout << "Territory id: " <<pT->getTerritoryId() <<endl;
                        }

                        //get all adjacent territory of each of your territory
                        cout << "All Adjacent territory\n";
                        for(auto &t: *territory){
                            auto adjacent_territory = generatedMap->getAllAdjacentTerritories(*t);
                            cout << "Adjacent territory of :" << t->getTerritoryId()<<endl;
                            for(auto &adj: adjacent_territory){
                                cout << "Territory Id : "<<adj->getTerritoryId() << endl;
                            }
                        }
                        cout << "Choose one for your territory. Choose by Id.\n";
                        cin >> st;
                        cout << "Choose one for adjacent territory. Choose by Id.\n";
                        cin >> tt;
                        cout << "How many army would you like to send?\n";
                        cin >> armyNum;

                        for(auto &pT: *territory){
                            if(pT->getTerritoryId() == st){
                                for(auto &t: *territory){
                                    auto adjacent_territory = generatedMap->getAllAdjacentTerritories(*t);
                                    for(auto &adj: adjacent_territory){
                                        if(adj->getTerritoryId() == tt){
                                            // create advance obj
                                            auto *advance = new Advance(i,pT,adj,armyNum);
                                            i->issueOrders(advance);
                                        }
                                    }
                                }
                            }
                        }
                        correct = false;
                    } else if (command == "Bomb") {
                        cout << "you chose bomb\n";
                        // bomb need the player, and the target territory
                        // The territory needs to be an adjacent territory
                        // list all adjacent territory
                        auto territory = i->getTerritoryList();
                        for(auto &t: *territory){
                            auto adjacent_territory = generatedMap->getAllAdjacentTerritories(*t);
                            for(auto &adj: adjacent_territory){
                                cout << "Adjacent Territory Id : "<<adj->getTerritoryId() << endl;
                            }
                        }
                        cout << "Which one would you like to bombard? Choose by ID:\n";
                        int bombId;
                        cin >> bombId;
                        for(auto &t: *territory){
                            auto adjacent_territory = generatedMap->getAllAdjacentTerritories(*t);
                            for(auto &adj: adjacent_territory){
                                if(adj->getTerritoryId() == bombId){
                                    Bomb *bomb = new Bomb(i,adj);
                                    i->issueOrders(bomb);
                                }
                            }
                        }
                        correct = false;
                    } else if (command == "Blockade") {
                        cout << "you chose blockade\n";
                        // list all territory user control.
                        auto territory = i->getTerritoryList();
                        //target territory;
                        int t;
                        for(auto &pTerritory : *territory){
                            cout << "Territory ID: " << pTerritory->getTerritoryId() << " Territory Name : " << pTerritory->getName() << endl;
                        }
                        cout << "Which territory would you like to use Blockade. Chose by id\n";
                        cin >> t;
                        for(auto &e : *territory){
                            if(e->getTerritoryId() == t){
                                cout << "This is the territory you chose: " << t << endl;
                                auto *blockade = new Blockade(i,e);
                                i->issueOrders(blockade);
                            }
                        }
                        correct = false;
                    } else if (command == "Airlift") {
                        cout << "you chose airlift\n";
                        int sourceT;
                        int targetT;
                        int armyNum;
                        Territory *sourceTerritory;
                        Territory *targetTerritory;
                        //Airlift need player, fromT, toT, army num
                        //get list of controlled territory and other territory;
                        auto territory = i->getTerritoryList();
                        // get list of all territory
                        for(auto &allpl: *playerList){
                            auto plT = allpl->getTerritoryList();
                            cout << "Territory of Player: " <<allpl->getPlayerName() << endl;
                            for(auto &TiD: *plT){
                                cout << "Territory Id: " << TiD->getTerritoryId() << endl;
                            }
                        }
                        auto AllNeutralT = neutral->getTerritoryList();
                        cout << "Neutral Territory Id\n";
                        for(auto &NTiD: *AllNeutralT){
                            cout << "Territory Id: " <<NTiD->getTerritoryId()<<endl;
                        }
                        cout << "Chose one of your territory\n";
                        cin >> sourceT;
                        cout << "Chose one of the other's territory\n";
                        cin >> targetT;
                        // find source territory
                        for(auto &pTerritory : *territory){
                            if(pTerritory->getTerritoryId() == sourceT){
                                sourceTerritory = pTerritory;
                            }
                        }

                        // find target territory
                        for(auto &allpl: *playerList){
                            auto plT = allpl->getTerritoryList();
                            for(auto &TiD: *plT){
                                if(TiD->getTerritoryId() == targetT){
                                    targetTerritory = TiD;
                                }
                            }
                        }
                        for(auto &NTiD: *AllNeutralT){
                            if(NTiD->getTerritoryId() == targetT){
                                targetTerritory = NTiD;
                            }
                        }
                        cout << "How many army would you like to send?\n";
                        cin >> armyNum;
                        // create Airlift obj
                        auto *airlift = new Airlift(i,sourceTerritory,targetTerritory, armyNum);
                        i->issueOrders(airlift);
                        correct = false;
                    } else if (command == "Negotiate") {
                        cout << "you chose negotiate\n";
                        //print all other player
                        cout << "Please chose your target player by id\n";
                        for(auto &j: *playerList){
                            if(i != j){
                                cout << "Player Id : " << j->getPlayerId() << ". Player Name : "<< j->getPlayerName()<<endl;
                            }
                        }
                        int target;
                        cin >> target;
                        cout << "You chose Player: " << target <<endl;
                        for(auto &y: *playerList){
                            if(y->getPlayerId() == target){
                                cout << "this is the player's id that you choose " << y->getPlayerId() << endl;
                                auto *negotiate = new Negotiate(i,i+2);
                                i->issueOrders(negotiate);
                            }
                        }
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
                    x[i->getPlayerId() - 1] = 1;
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
            cout << "------------ Player : " << i->getPlayerName() << " ------------" << endl;
            orderlist = i->getOrderList();
            vector<Order *> *listOfOrders = orderlist->getOrderList();
            if(!listOfOrders->empty()){
                auto it = listOfOrders->begin();
                string orderType = (*it)->getOrderType();
                if(orderType == "deploy"){
                    bool validation = (*it)->validate(generatedMap);
                    if(validation){
                        (*it)->execute(generatedMap);
                    }
                    orderlist->remove(*it);
                } else if (orderType == "bomb"){
                    bool validation = (*it)->validate(generatedMap);
                    if(validation){
                        (*it)->execute(generatedMap);
                    }
                    orderlist->remove(*it);
                } else if (orderType == "advance"){
                    bool validation = (*it)->validate(generatedMap);
                    if(validation){
                        (*it)->execute(generatedMap);
                    }
                    orderlist->remove(*it);
                } else if (orderType == "blockade"){
                    bool validation = (*it)->validate(generatedMap);
                    if(validation){
                        (*it)->execute(generatedMap);
                    }
                    orderlist->remove(*it);
                } else if (orderType == "airlift"){
                    bool validation = (*it)->validate(generatedMap);
                    if(validation){
                        (*it)->execute(generatedMap);
                    }
                    orderlist->remove(*it);
                } else if (orderType == "negotiate"){
                    bool validation = (*it)->validate(generatedMap);
                    if(validation){
                        (*it)->execute(generatedMap);
                    }
                    orderlist->remove(*it);
                }
            } else {
                exit_count3 ++;
            }
        }
    }
}

string GameEng::stringToLog() {
    return "Game Engine: " + userCmd;
}
