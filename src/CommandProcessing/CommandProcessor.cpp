#include "CommandProcessor.h"
#include <iostream>
#include <fstream>
#include <regex>

/////////////////

Command::Command(string cmd){
    command = cmd;
}

Command::Command(const Command& c){
    command = c.command;
    effect = c.effect;
}

void Command::saveEffect(string e) {
    Notify(this);
    effect = e;
}
string Command::stringToLog() {
    return "Command stringToLog";
}

ostream &operator<<(ostream &output, Command &C ) {
    output << "Command: " << C.command << endl;
    output << "Effect: " << C.effect << endl;
    return output;
}

Command&Command::operator=(const Command& c){
    command = c.command;
    effect = c.effect;
    return *this;
}

/////////////////

CommandProcessor::CommandProcessor(const CommandProcessor& c){
    lc = c.lc;
}

void CommandProcessor::getCommand() {
    string cmd = readCommand();
    saveCommand(cmd);
}

string CommandProcessor::readCommand() {
    string cmd;
    cout << "Please enter a command: \n";
    getline(cin, cmd);
    return cmd;
}

void CommandProcessor::saveCommand(string cmd) {
    Command c(cmd);
    // Save effect
    c.saveEffect(cmd);
    lc->push_back(c);
    Notify(this);
}

// If valid, returns the passing command
string CommandProcessor::validate(GameState gs) {
    string c = lc->back().getCommand();

    regex loadRegex ("loadmap\\s.+");
    regex playerRegex("addplayer\\s.+");

    // Loadmap is usable
    if(regex_match (c, loadRegex) && (gs == GameState::start || gs == GameState::maploaded))
        lc->back().saveEffect("maploaded");
    // Validatemap is usable
    else if(c == "validatemap" && gs == GameState::maploaded)
        lc->back().saveEffect("mapvalidated");
    // Addplayer is usable
    else if(regex_match (c, playerRegex) && (gs == GameState::mapvalidated || gs == GameState::playeradded))
        lc->back().saveEffect("playersadded");
    // Gamestart is usable
    else if(c == "gamestart" && gs == GameState::playeradded)
        lc->back().saveEffect("assignreinforcement");
    // Replay is usable
    else if(c == "replay" && gs == GameState::win)
        lc->back().saveEffect("start");
    // Quit is usable
    else if(c == "quit" && gs == GameState::win)
        lc->back().saveEffect("exit program");
    // Command is not usable
    else
        lc->back().saveEffect("Error: Invalid input.");

    return c;
}

string CommandProcessor::stringToLog() {
    return "CommandProcessor stringToLog";
}

ostream &operator<<(ostream &output, CommandProcessor &C ) {
    output << C.lc->back().getCommand() << " " << C.lc->back().getEffect();
    return output;
}

CommandProcessor&CommandProcessor::operator=(const CommandProcessor& c){
    lc = c.lc;
    return *this;
}

//////////////

FileCommandProcessorAdapter::FileCommandProcessorAdapter(const FileCommandProcessorAdapter& f){
    flr = f.flr;
}

string FileCommandProcessorAdapter::readCommand() {
    return flr->readLineFromFile();
}

ostream &operator<<(ostream &output, FileCommandProcessorAdapter &F ) {
    output << F.readCommand();
    return output;
}

FileCommandProcessorAdapter&FileCommandProcessorAdapter::operator=(const FileCommandProcessorAdapter& f){
    flr = f.flr;
    return *this;
}

//////////////

FileLineReader::FileLineReader(const FileLineReader& f){
    filename = f.filename;
}

FileLineReader::FileLineReader(string fn) {
    filename = fn;
    inputFileStream.open(filename,  ios::in);
    if(!inputFileStream.is_open()){
        cout << "File does not exist or cannot be opened.\n";
        exit(0);
    }
}

string FileLineReader::readLineFromFile() {
    string cmd;

    // End if file is empty
    if (inputFileStream.eof())
    {
        cout << "End of file.\n";
        inputFileStream.close();
        exit(0);
    }

    getline(inputFileStream, cmd);
    cout << "INPUT: " << cmd << endl;
    return cmd;
}

ostream &operator<<(ostream &output, FileLineReader &F ) {
    output << F.filename;
    return output;
}

FileLineReader&FileLineReader::operator=(const FileLineReader& f){
    filename = f.filename;
    return *this;
}
