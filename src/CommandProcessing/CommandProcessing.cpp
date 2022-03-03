#include "CommandProcessing.h"
#include <iostream>
#include <regex>

/////////////////

Command::Command(string cmd){
    command = cmd;
}


/////////////////

void CommandProcessing::getCommand() {
    string cmd = readCommand();
    saveCommand(cmd);
}

string CommandProcessing::readCommand() {
    string cmd;
    cout << "Please enter a command: \n";
    getline(cin, cmd);
    return cmd;
}

void CommandProcessing::saveCommand(string cmd) {
    Command c(cmd);
    // Save effect
    c.saveEffect(cmd);
    lc->push_back(c);
}

// If valid, returns the passing command
string CommandProcessing::validate(GameState gs) {
    string c = lc->back().getCommand();

    regex loadRegex ("loadmap\\s.+");
    regex playerRegex("addplayer\\s.+");

    // Loadmap, Validatemap, Addplayer, Gamestart, Replay, or Quit are usable
    if((regex_match (c, loadRegex) && (gs == GameState::start || gs == GameState::maploaded)) ||
        (c == "validatemap" && gs == GameState::maploaded) ||
        (regex_match (c, playerRegex) && (gs == GameState::mapvalidated || gs == GameState::playeradded)) ||
        (c == "gamestart" && gs == GameState::playeradded) ||
        (c == "replay" && gs == GameState::win) ||
        (c == "quit" && gs == GameState::win)
    )
        return c;

    // Command is not usable
    lc->back().saveEffect("Error: Invalid input.");
    return lc->back().getEffect();
}
