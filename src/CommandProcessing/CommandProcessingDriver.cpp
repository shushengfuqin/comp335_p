
#include <iostream>
#include <string>

#include "../GameEngine/GameEngine.h"
#include "CommandProcessing.h"
using namespace std;

class CommandProcessingDriver{
public:
    CommandProcessingDriver()= default;
    ~CommandProcessingDriver()= default;
    static void callCommandProcessingDriver() {

        // Initialize gamestate at state and update upon state change
        GameState currentState = start;
        GameState* currentStatePtr = &currentState;

        // Initializa game play boolean.
        bool play = true;
        bool* playPtr = &play;

        // Initialize var for keeping user's choice
        string userChoice;
        string* userChoicePtr = &userChoice;

        GameEng ge;
        CommandProcessing cp;
        // while true keep the game playing.
        while(*playPtr) {
            switch (currentState) {
                case start:
                    *userChoicePtr = ge.startFunc();
                    if (userChoice == "loadmap") {
                        *currentStatePtr = maploaded;
                    }
                case maploaded:
                    *userChoicePtr = ge.maploadedFunc();
                    if (userChoice == "validatemap") {
                        *currentStatePtr = mapvalidated;
                    }
                case mapvalidated:
                    *userChoicePtr = ge.mapvalidatedFunc();
                    if (userChoice == "addplayer") {
                        *currentStatePtr = playeradded;
                    }
                case playeradded:
                    *userChoicePtr = ge.playeraddedFunc();
                    if (userChoice == "assigncountries") {
                        *currentStatePtr = assignreignforcement;
                    }
                case assignreignforcement:
                    *userChoicePtr = ge.assignreinforcementFunc();
                    if (userChoice == "issueorder") {
                        *currentStatePtr = issueorders;
                    }
                case issueorders:
                    *userChoicePtr = ge.issueordersFunc();
                    if (userChoice == "endissuorders") {
                        *currentStatePtr = executeorders;
                    }
                case executeorders:
                    *userChoicePtr = ge.executeordersFunc();
                    if (userChoice == "endexecorders") {
                        *currentStatePtr = assignreignforcement;
                    } else if (userChoice == "win") {
                        *currentStatePtr = win;
                    }
                case win:
                    *userChoicePtr = ge.winFunc();
                    if (userChoice == "play") {
                        *currentStatePtr = start;
                    } else if (userChoice == "end") {
                        // since the user chose to quit, therefore, change the bool to play false, to close.
                        *playPtr = false;
                        break;
                    }
                    continue;
                default:
                    cout << "Error: Invalid input\n";
            }
        }
    }
};


