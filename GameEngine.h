#ifndef GameEngine
#include <iostream>
#include <string>
#pragma once
using namespace std;

class GameEngine{
public:
    GameEngine();
    ~GameEngine();
    string static startFunc();
    string static maploadedFunc();
    string static mapvalidatedFunc();
    string static playeraddedFunc();
    string static assignreinforcementFunc();
    string static issueordersFunc();
    string static executeordersFunc();
    string static winFunc();

};

#endif