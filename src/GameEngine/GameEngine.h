//
// Created by Gin on 2022-02-13.
//

#ifndef COMP335_P_GAMEENGINE_H
#define COMP335_P_GAMEENGINE_H

#include <iostream>
#include <string>
#include <list>
#include "../CommandProcessing/CommandProcessing.h"
#include "GameState.h"

#pragma once
using namespace std;

class GameEng;
class CommandProcessing;

class GameEng{
public:
    GameEng();
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
    CommandProcessing *cmdProc;
    GameState currentState;

};

#endif //COMP335_P_GAMEENGINE_H
