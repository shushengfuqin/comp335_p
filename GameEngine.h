//
// Created by Gin on 2022-02-13.
//

#ifndef COMP335_P_GAMEENGINE_H
#define COMP335_P_GAMEENGINE_H

#include <iostream>
#include <string>
#pragma once
using namespace std;
enum GameState
{
    start,
    maploaded,
    mapvalidated,
    playeradded,
    assignreignforcement,
    issueorders,
    executeorders,
    win
};

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
};
#endif //COMP335_P_GAMEENGINE_H
