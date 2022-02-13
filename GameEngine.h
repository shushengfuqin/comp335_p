//
// Created by Gin on 2022-02-13.
//

#ifndef COMP335_P_GAMEENGINE_H
#define COMP335_P_GAMEENGINE_H
#include <iostream>
#include <string>
#pragma once
using namespace std;

class GameEng{
public:
    GameEng();
    ~GameEng();
    string static startFunc();
    string static maploadedFunc();
    string static mapvalidatedFunc();
    string static playeraddedFunc();
    string static assignreinforcementFunc();
    string static issueordersFunc();
    string static executeordersFunc();
    string static winFunc();
};
#endif //COMP335_P_GAMEENGINE_H
