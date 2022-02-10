#ifndef GameEngine.h
#define GameEngine.h
#include <iostream>;
#include <string>
#pragma once
using namespace std;

extern int* userInputptr;
// State class for the start state
class startState{
public:
    // constructor
    startState();
    // destroyer
    ~startState();
    // Method to run startState including transfer method
    string static startFunc();
};

// map loaded class for the maploaded state
class maploadedState{
public:
    // constructor
    maploadedState();
    // destroyer
    ~maploadedState();
    // Method to run maploadedState including transfer method
    string static maploadedFunc();
};

// map validated class for the mavalidated state
class mapvalidatedState{
public:
    // constructor
    mapvalidatedState();
    // destroyer
    ~mapvalidatedState();
    // Method to run mapvalidatedState including transfer method
    string static mapvalidatedFunc();
};

// player added class for the player added state
class playeraddedState{
public:
    // constructor
    playeraddedState();
    // destroyer
    ~playeraddedState();
    // Method to run playeraddedState including transfer method
    string static playeraddedFunc();
};

// assign reignforcement class for the reignforcement state
class assignreinforcementState{
public:
    // constructor
    assignreinforcementState();
    // destroyer
    ~assignreinforcementState();
    // Method to run assignreinforcementState including transfer method
    string static assignreinforcementFunc();
};

class issueordersState{
public:
    // constructor
    issueordersState();
    // destroyer
    ~issueordersState();
    // Method to run issueordersState including transfer method
    string static issueordersFunc();
};

class executeordersState{
public:
    // constructor
    executeordersState();
    // destroyer
    ~executeordersState();
    // Method to run executeordersState including transfer method
    string static executeordersFunc();
};

class winState{
public:
    // constructor
    winState();
    // destroyer
    ~winState();
    // Method to run winState including transfer method
    string static winFunc();
};
#endif