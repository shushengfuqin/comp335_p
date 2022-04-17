#include "GameEngine.h"
#include <iostream>
#include <regex>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

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
regex tournamentRegex("tournament\\s-M\\s([^\\s]+\\s){1,5}-P\\s([^\\s]+\\s){2,4}-G\\s[1-4]\\s-D\\s([1-4][0-9]|50)");
//tournament -M TEST -P TEST -G 4 -D 10
//tournament -M TEST 1 2 3 4 -P TEST 1 -G 4 -D 10
//tournament -M TEST 1 2 3 4 5 -P TEST 1 -G 4 -D 10
//comp345_p -M TEST 1 2 3 4 -P TEST 1 -G 4 -D 10

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
    cout << "2 - tournament -M <listofmapfiles (1-5)> -P <listofplayerstrategies (2-4)> -G <numberofgames (1-4)> -D <maxnumberofturns (10-50)>\n";
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
        else if (regex_match (cmdInput, tournamentRegex)){
            cout << "Moving to the tournament state\n";
            Notify(this);

            return "tournament";
        }
        else{
            cout << "Error: Please enter an valid command\n";
            cmdProc->getCommand();
            continue;
        }
    }

}

/////////////

string GameEng::tournamentFunc()
{
    // Extract command and save it in Game Engine
    cmdProc->tournamentData(&tMaps, &tPlayers, tGames, tTurns);

    bool error = false;

    // Check if map can load
    auto it = tMaps.begin();
    while (it != tMaps.end())
    {
        auto curr = it++;
        pMapLoader = new MapLoader("../maps/" + *curr + ".map");

        // tournament -M canada win solar lunar -P TEST1 TEST2 -G 4 -D 10
        // Failed to load filename
        if (!pMapLoader->success) {
            tMaps.erase(curr);
            error = true;
            it--;
        }
    }

    if(error)
        cout << "All invalid maps have been removed." << endl;

    if(tMaps.size() == 0){
        cout << "There were no valid maps chosen. Please insert valid maps when starting a tournament." << endl << endl;
        return "start";
    }

    cout << "Tournament Mode:\n";
    cout << "M: ";
    for(int i = 0; i < tMaps.size(); i++){
        cout << tMaps[i] << " ";
    }
    cout << "\nP: ";
    for(int i = 0; i < tPlayers.size(); i++){
        if(tPlayers[i] != "")
            cout << tPlayers[i] << " ";
    }
    cout << "\nG: " << tGames;
    cout << "\nD: " << tTurns;
    cout << endl;

    //exit(1);
    return "startTournament";
}

bool GameEng::LoadMap(const string& name){
    pMapLoader = new MapLoader("../maps/"+name+".map");

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
            PlayerStrategy *ps = new Human();
            string playerName = cmdInput.substr(cmdInput.find(' ') + 1);
            auto *player = new Player(playerName);
            player->setPlayerId(++playerCount);
            player->setStrategy(ps);
            player->setStrategyString(ps->getStrategyName());
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
                // *** ADD PLAYER HERE ***
                PlayerStrategy *ps = new Human();
                string playerName = cmdInput.substr(cmdInput.find(' ') + 1);
                auto *player = new Player(playerName);
                player->setPlayerId(++playerCount);
                player->setStrategy(ps);
                player->setStrategyString(ps->getStrategyName());
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
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            auto rng = std::default_random_engine { seed };
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
//            delete generatedMap;
//            generatedMap = NULL;
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
    playerCount = 0;

    // Continue until start up phase is complete
    while(getState() != win && getState() != assignreignforcement && getState() != tournament){
        switch (getState()) {
            case start:{
                string sf = startFunc();

                if (sf == "loadmap") {
                    setState(maploaded);
                }
                else if(sf == "tournament"){
                    if(tournamentFunc() == "startTournament")
                        setState(tournament);
                    else
                        setState(start);
                }
                break;
            }
            case maploaded:
                if (maploadedFunc() == "validatemap") {
                    setState(mapvalidated);
                }
                break;
            case mapvalidated:
                if (mapvalidatedFunc() == "addplayer") {
                    setState(playeradded);
                }
                break;
            case playeradded:
                if (playeraddedFunc() == "assigncountries") {
                    setState(assignreignforcement);
                }
                break;
            default:
                break;
        }
    }
}

void GameEng::mainGameLoop(){
    turnNum = 1;
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
        //check the each player's territory size
        for(auto pl : *playerList){
            if(pl->getTerritoryList()->empty()){
                playerList->push_back(pl);
                playerCount--;
            }
        }
    }
    delete (pMapLoader);
    pMapLoader = NULL;
}

void GameEng::tournamentGameLoop(){
    string results[tMaps.size()][tGames];

    // TODO: CREATE AND ADD PLAYERS
    for(int i = 0; i < tPlayers.size(); i++) {
        PlayerStrategy *ps;
        if(tPlayers[i] =="Aggressive")
            ps = new Aggressive();
        else if(tPlayers[i] =="Benevolent")
            ps = new Benevolent();
        else if(tPlayers[i] =="Neutral")
            ps = new Neutral();
        else if(tPlayers[i] =="Cheater")
            ps = new Cheater();
        else
            ps = new Human();

        string playerName = tPlayers[i];
        auto *player = new Player(playerName + "_" + to_string(i));
        player->setPlayerId(++playerCount);
        player->setStrategy(ps);
        player->setStrategyString(ps->getStrategyName());
        playerList->push_back(player);
        cout << "Added player: " << playerName << endl;
    }
    
    // Map Loop
    for(int i = 0; i < tMaps.size(); i++){
        LoadMap(tMaps[i]);

        // Game Loop
        for(int j = 0; j < tGames; j++){

            // TODO: ASSIGN TERRITORIES HERE
            // Fairly distributing the territories among all players
            neutral = new Player("Bitch Ass");
            neutral->setPlayerId(-1);
            PlayerStrategy *ns = new Neutral();
            neutral->setStrategy(ns);
            neutral->setStrategyString(ns->getStrategyName());
            //playerList->push_back(neutral);
            generatedMap->assignTerritoriesToPlayers(*playerList);
            generatedMap->assignTerritoriesToNeutralPlayer(neutral, *playerList);

            // Randomly determine the order of play of the players in the game
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            auto rng = std::default_random_engine { seed };
            shuffle(playerList->begin(), playerList->end(), rng);

            // Each player to draw 2 cards each from the deck
            for(int i = 0; i < playerCount; i++){
                Player *p = playerList->at(i);
                gameDeck->draw(*p->getHand());
                gameDeck->draw(*p->getHand());
            }

            cout << "STARTING MAP " << (i+1) << " - GAME " << (j+1) << endl;
            
            turnNum = 1;
            //while the amount of player is not 1 the main game loop will keep looping.
            // Also when we haven't reached the turn limit
            while(playerCount != 1 && turnNum <= tTurns){
                cout << "------------ TURN : " << turnNum << " ------------\n";
                // call the reinforcementphase
                if(turnNum != 1){
                    reinforcementPhase();
                }
                issueOrdersPhase();
                executeOrdersPhase();
                turnNum++;
                //check the each player's territory size
                for(auto pl : *playerList){
                    if(pl->getTerritoryList()->empty()){
                        playerList->push_back(pl);
                        playerCount--;
                    }
                }

                turnNum++;
            }

            // TODO: DETERMINE THE WINNER
            // Stalemate
            if(turnNum > tTurns)
                results[i][j] = "Draw";
            else{

                string winner;
                // Find the winner
                for(auto pl : *playerList){
                    if(pl->getArmyNum() > 0)
                        winner = pl->getPlayerName();
                }
                results[i][j] = winner;
            }

            //results[i][j] = "PLACEHOLDER " + to_string(i) + " - " + to_string(j);

            // Reset player territories and cards;
            for(int i = 0; i < playerCount; i++){
                Player *p = playerList->at(i);
                p->resetPlayer(*gameDeck);
            }

            cout << "ENDING MAP " << (i+1) << " - GAME " << (j+1) << endl;
        }

        // Clear map loader
        delete (pMapLoader);
        pMapLoader = NULL;
    }

    // tournament -M canada win solar -P Aggressive Cheater -G 4 -D 20
    // tournament -M canada win solar -P Aggressive Aggressive -G 4 -D 20
    // tournament -M canada win solar -P Aggressive Neutral -G 4 -D 20
    // tournament -M canada win solar -P Benevolent Neutral -G 4 -D 20
    /// End the tournament
    // Print results
    // TODO: ALSO PRINT RESULTS TO LOG (somehow)
    string resultString = "\nResults: \n       | ";
    // Game Loop
    for(int i = 0; i < tGames; i++) {
        resultString += "    GAME " + to_string(i+1) + "     | ";
    }

    resultString += "\n";

    for(int i = 0; i < tMaps.size(); i++){
        resultString += tMaps[i] + " | ";
        // Game Loop
        for(int j = 0; j < tGames; j++) {
            resultString += results[i][j] + " | ";
        }
        resultString += "\n";
    }

    resultString += "\n\n";

    // Output to log
    userCmd = resultString;
    Notify(this);
    // Output to screen
    cout << resultString;

    // Clear map and player strategy lists
    tMaps.clear();
    tPlayers.clear();

    setState(win);
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
    // I need a bool to check if it's deploy or not
    // this bool will be false after deploy mode is done
    bool deployOrNot = true;
    cout << "------------ Issue Orders Phase ------------\n";
    //check the player Strat
    // count if there are still player not done in deploying
    int exit_Count = 0;
    // all player in deploy mode
    while (exit_Count < playerCount) {
        for (auto &i: *playerList) {
            // send to issueOrders Player*
            i->issueOrders(i,generatedMap,deployOrNot, playerList);
            if (i->getPlayerStrategyString().compare("Cheater") || i->getPlayerStrategyString().compare("Neutral")) {
                exit_Count++;
            }else{
                if (i->getArmyNum() == 0) {
                    exit_Count++;
                }
            }
        }
    }
    deployOrNot = false;

    // issue order
    int exit_Count2 = 0;
    int x[playerCount];
    for(int i = 0; i < playerCount; i++){
        x[i] = 0;
    }
    while(exit_Count2 < playerCount){
        for(auto &i: *playerList){
            // send i, map, playerList
            cout << "------------ Player : " << i->getPlayerName() << " ------------" << endl;
            if(x[i->getPlayerId() - 1] !=1){

                string done;
                i->issueOrders(i,generatedMap,deployOrNot, playerList);
                if(!i->getPlayerStrategyString().compare("Human")){
                    cout << "are you done with issue Order? If yes type Y. Else type anything\n";
                    cin >> done;
                    if(done == "Y"){
                        exit_Count2++;
                        x[i->getPlayerId() - 1] = 1;
                    }
                }else{
                    cout << "Player " << i->getPlayerName() << " is done with the order\n";

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
                    (*it)->execute2(generatedMap);
                    orderlist->remove(*it);
                } else if (orderType == "bomb"){
                    (*it)->execute2(generatedMap);
                    orderlist->remove(*it);
                } else if (orderType == "advance"){
                    (*it)->execute2(generatedMap);
                    orderlist->remove(*it);
                } else if (orderType == "blockade"){
                    (*it)->execute2(generatedMap);
                    orderlist->remove(*it);
                } else if (orderType == "airlift"){
                    (*it)->execute2(generatedMap);
                    orderlist->remove(*it);
                } else if (orderType == "negotiate"){
                    (*it)->execute2(generatedMap);
                    orderlist->remove(*it);
                }else if (orderType == "cheat"){
                    (*it)->execute2(generatedMap);
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
