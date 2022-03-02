#ifndef COMP335_P_COMMANDPROCESSING_H
#define COMP335_P_COMMANDPROCESSING_H

#include <iostream>
#include <string>
#include <list>
#include "../GameEngine/GameEngine.h"

#pragma once
using namespace std;

class CommandProcessing;
class Command;

class CommandProcessing{
public:
    CommandProcessing() = default;
    ~CommandProcessing() = default;
    Command getCommand();
protected:
    string readCommand();
    void saveCommand(string cmd);
private:
    bool validate(GameState gs, Command cmd);
    list<Command> *lc;
};

class Command {
public:
    Command() = default;
    Command(string cmd);
    ~Command() = default;
    void saveEffect(string fx) {effect = fx;};
    string getCommand() {return command;}
private:
    string command;
    string effect;
};


#endif //COMP335_P_COMMANDPROCESSING_H
