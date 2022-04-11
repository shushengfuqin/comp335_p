//
// Created by Gin on 2022-02-13.
//

#ifndef COMP335_P_GAMEENGINE_H
#define COMP335_P_GAMEENGINE_H

#include <iostream>
#include <string>
#include <list>
#include "../CommandProcessing/CommandProcessor.h"
#include "GameState.h"
#include "../Observer/LoggingObserver.h"
#include "../Map/Map.h"
#include "../Cards/Cards.h"
#include "../Player//Player.h"
#include "../Order/Orders.h"

#pragma once
using namespace std;

class GameEng;
class CommandProcessor;
class FileLineReader;
class FileCommandProcessorAdapter;

class GameEng:public ILoggable, public Subject{
public:
    GameEng();
    GameEng(CommandProcessor *cp);
    GameEng(FileLineReader *flr);
    ~GameEng();
    string startFunc();
    string tournamentFunc();
    string maploadedFunc();
    string mapvalidatedFunc();
    string playeraddedFunc();
    static string assignreinforcementFunc();
    static string issueordersFunc();
    static string executeordersFunc();
    string winFunc();
    void setState(GameState gs){ currentState = gs; }
    GameState getState() { return currentState; }
    CommandProcessor *cmdProc;
    GameState currentState;
    string cmdInput;
    string stringToLog() override;

    // game phases
    void startUpPhase();
    void mainGameLoop();
    void reinforcementPhase() const;
    void issueOrdersPhase();
    void executeOrdersPhase();

    MapLoader *pMapLoader;
    Map *generatedMap;
    bool LoadMap(const string& name);

    vector<Player*>* playerList;
    Player* neutral;
    Orderslist* orderlist;
    int playerCount = 0;

    Deck* gameDeck;

    void Transition();

    // Tournament Variables
    vector<string> tMaps;
    vector<string> tPlayers;
    int tGames;
    int tTurns;
private:
    string userCmd;
    int turnNum = 1;
};

#endif //COMP335_P_GAMEENGINE_H
