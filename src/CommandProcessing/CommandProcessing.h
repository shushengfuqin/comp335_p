#ifndef COMP335_P_COMMANDPROCESSING_H
#define COMP335_P_COMMANDPROCESSING_H

#include <iostream>
#include <string>
#include <list>
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameState.h"

#pragma once
using namespace std;

class GameEng;
class CommandProcessing;
class Command;

class CommandProcessing{
public:
    CommandProcessing() = default;
    ~CommandProcessing() = default;
    void getCommand();
    string validate(GameState gs);
protected:
    string readCommand();
    void saveCommand(string cmd);
private:
    list<Command> *lc = new list<Command>();
};

class Command {
public:
    Command() = default;
    Command(string cmd);
    ~Command() = default;
    void saveEffect(string e) {effect = e;}
    string getEffect() {return effect;}
    string getCommand() {return command;}
private:
    string command;
    string effect;
};


#endif //COMP335_P_COMMANDPROCESSING_H
