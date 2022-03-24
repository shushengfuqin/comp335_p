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
    Command(const Command& c);
    ~Command() = default;
    void saveEffect(string e);
    string getEffect() {return effect;}
    string getCommandText() {return command;}
    string stringToLog() override;
    friend ostream &operator<<(ostream &output, Command &C );
    Command& operator=(const Command& c);
private:
    string command;
    string effect;

};


// TARGET
class CommandProcessor: public ILoggable, public Subject{
public:
    CommandProcessor() = default;
    CommandProcessor(const CommandProcessor& c);
    ~CommandProcessor() = default;
    void getCommand();
    string validate(GameState gs);
    string stringToLog() override;
    friend ostream &operator<<(ostream &output, CommandProcessor &C );
    CommandProcessor& operator=(const CommandProcessor& C);
protected:


private:
    virtual string readCommand();
    void saveCommand(const string& cmd);
    list<Command> *lc = new list<Command>();
};

// ADAPTEE
class FileLineReader {
public:
    FileLineReader(string filename);
    FileLineReader(const FileLineReader& f);
    ~FileLineReader() = default;
    string readLineFromFile();
    friend ostream &operator<<(ostream &output, FileLineReader &F );
    FileLineReader& operator=(const FileLineReader& F);
private:
    string filename;
    ifstream inputFileStream;
};

// ADAPTER
class FileCommandProcessorAdapter : public CommandProcessor{
public:
    FileCommandProcessorAdapter(FileLineReader * flr) {this->flr = flr;}
    FileCommandProcessorAdapter(const FileCommandProcessorAdapter& f);
    ~FileCommandProcessorAdapter() = default;
    friend ostream &operator<<(ostream &output, FileCommandProcessorAdapter &F);
    FileCommandProcessorAdapter& operator=(const FileCommandProcessorAdapter& F);
protected:
    string readCommand();
private:
    FileLineReader *flr;
};



#endif //COMP335_P_COMMANDPROCESSOR_H
