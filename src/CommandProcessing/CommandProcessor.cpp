#include "CommandProcessor.h"
#include <iostream>
#include <sstream>
#include <regex>
#include <utility>

/////////////////

Command::Command(string cmd){
    command = std::move(cmd);
}

Command::Command(const Command& c){
    command = c.command;
    effect = c.effect;
}

void Command::saveEffect(string e) {
    effect = std::move(e);
    Notify(this);
}
string Command::stringToLog() {
    return "Command stringToLog: " + effect ;
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

CommandProcessor::CommandProcessor(string cmd){
    saveCommand(cmd);
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

void CommandProcessor::saveCommand(const string& cmd) {
    Command c(cmd);
    // Save effect
    lc->push_back(c);
    Notify(this);
}

// If valid, returns the passing command
string CommandProcessor::validate(GameState gs) {
    string c = lc->back().getCommandText();

    regex loadRegex ("loadmap\\s.+");
    regex playerRegex("addplayer\\s.+");
    regex tournamentRegex("tournament\\s-M\\s([^\\s]+\\s){1,5}-P\\s([^\\s]+\\s){2,4}-G\\s[1-4]\\s-D\\s([1-4][0-9]|50)");

    // Loadmap is usable
    if(regex_match (c, loadRegex) && (gs == GameState::start || gs == GameState::maploaded))
        lc->back().saveEffect("maploaded");
    // Tournament is usable
    else if(regex_match (c, tournamentRegex) && gs == GameState::start)
        lc->back().saveEffect("tournament");
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

void CommandProcessor::tournamentData(vector<string>* m, vector<string>* p, int& g, int& d){
    // Change data to string array
    std::stringstream ss(lc->back().getCommandText());
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> tData(begin, end);

    int count = 0;
    char phase = 'M';
    for(int i = 2; i < tData.size(); i++){
        switch(phase){
            case 'M':
                if(std::string(tData[i]) == "-P"){
                    phase = 'P';
                    count = 0;
                }
                else
                   m->push_back(string(tData[i]));
                break;
            case 'P':
                if(std::string(tData[i]) == "-G"){
                    phase = 'G';
                    count = 0;
                }
                else
                    p->push_back(string(tData[i]));
                break;
            case 'G':
                if(std::string(tData[i]) == "-D")
                    phase = 'D';
                else
                    g = stoi(tData[i]);
                break;
            case 'D':
                    d = stoi(tData[i]);
                break;
        }
    }
}

string CommandProcessor::stringToLog() {
    return "CommandProcessor stringToLog: " + lc->back().getCommandText();
}

ostream &operator<<(ostream &output, CommandProcessor &C ) {
    output << C.lc->back().getCommandText() << " " << C.lc->back().getEffect();
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
