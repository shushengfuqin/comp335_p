//
// Created by Scrib on 2022-03-01.
//

#include "CommandProcessing.h"
#include <iostream>
#include <regex>

/////////////////

Command::Command(string cmd){
    command = cmd;
}


/////////////////

string CommandProcessing::readCommand() {
    string cmd;
    cin >> cmd;
    return cmd;
}

void CommandProcessing::saveCommand(string cmd) {
    Command c(cmd);
    //Command* c = new Command(cmd);
    lc->push_front(c);
}

bool CommandProcessing::validate(GameState gs, Command cmd) {
    string c = cmd.getCommand();
    regex loadRegex ("(loadmap )(.*)");
    regex playerRegex("(addplayer )(.*)");

    // Loadmap is not usable
    if(regex_match (c, loadRegex) && (gs == GameState::start || gs == GameState::maploaded))
        return false;

    // Validatemap is not usable
    if(c == "validatemap" && gs == GameState::maploaded)
        return false;

    // Addplayer is not usable
    if(regex_match (c, playerRegex) && (gs == GameState::mapvalidated || gs == GameState::maploaded))
        return false;

    // Gamestart is not usable
    if(c == "gamestart" && gs == GameState::playeradded)
        return false;

    // Replay is not usable
    if(c == "replay" && gs == GameState::win)
        return false;

    // Quit is not usable
    if(c == "quit" && gs == GameState::win)
        return false;

    // Command is usable
    return true;
}
