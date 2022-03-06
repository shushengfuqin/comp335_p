#ifndef COMP335_P_COMMANDPROCESSOR_H
#define COMP335_P_COMMANDPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameState.h"
#include "../Observer/LoggingObserver.h"

#pragma once
using namespace std;

class GameEng;
class CommandProcessor;
class Command;
class FileLineReader;
class FileCommandProcessorAdapter;

class Command:public ILoggable, public Subject {
public:
    Command() = default;
    Command(string cmd);
    ~Command() = default;
    void saveEffect(string e);
    string getEffect() {return effect;}
    string getCommand() {return command;}

    string stringToLog() override;
private:
    string command;
    string effect;
};


// TARGET
class CommandProcessor:public ILoggable, public Subject{
public:
    CommandProcessor() = default;
    ~CommandProcessor() = default;
    void getCommand();
    string validate(GameState gs);
    string stringToLog() override;
protected:
    virtual string readCommand();
    void saveCommand(string cmd);
private:
    list<Command> *lc = new list<Command>();
};

// ADAPTEE
class FileLineReader {
public:
    FileLineReader(string filename);
    ~FileLineReader() = default;
    string readLineFromFile();
private:
    ifstream inputFileStream;
};

// ADAPTER
class FileCommandProcessorAdapter : public CommandProcessor{
public:
    FileCommandProcessorAdapter(FileLineReader * flr) {this->flr = flr;}
    ~FileCommandProcessorAdapter() = default;
protected:
    string readCommand();
private:
    FileLineReader *flr;
};



#endif //COMP335_P_COMMANDPROCESSOR_H
