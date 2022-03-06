//
// Created by Gin on 2022-02-13.
//

#ifndef COMP335_P_GAMEENGINE_H
#define COMP335_P_GAMEENGINE_H

#include <iostream>
#include <string>
#include "../Observer/LoggingObserver.h"
#include <list>
#include "../CommandProcessing/CommandProcessor.h"
#include "GameState.h"

#pragma once
using namespace std;

class GameEng;
class CommandProcessor;
class FileLineReader;
class FileCommandProcessorAdapter;

class GameEng:public ILoggable,public Subject{
public:
    GameEng();
    GameEng(CommandProcessor *cp);
    GameEng(FileLineReader *flr);
    ~GameEng();
    string startFunc();
    string maploadedFunc();
    string mapvalidatedFunc();
    string playeraddedFunc();
    string assignreinforcementFunc();
    string issueordersFunc();
    string executeordersFunc();
    string winFunc();
    void setState(GameState gs){ currentState = gs; }
    GameState getState() { return currentState; }
    CommandProcessor *cmdProc;
    GameState currentState;
    string cmdInput;
    string stringToLog() override;
};

#endif //COMP335_P_GAMEENGINE_H
