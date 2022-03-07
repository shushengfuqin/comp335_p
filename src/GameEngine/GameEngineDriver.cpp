
#include <iostream>
#include <string>

#include "GameState.h"
#include "GameEngine.h"
using namespace std;

class GameEngineDriver{
public:
    GameEngineDriver()= default;;
    ~GameEngineDriver()= default;;
    static void callGameEngineDriver() {

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
        // while true keep the game playing.
        while(*playPtr) {
            switch (currentState) {
                case start:
                    *userChoicePtr = ge.startFunc();
                    if (*userChoicePtr == "loadmap") {
                        *currentStatePtr = maploaded;
                    }
                    continue;
                case maploaded:
                    *userChoicePtr = ge.maploadedFunc();
                    if (*userChoicePtr == "validatemap") {
                        *currentStatePtr = mapvalidated;
                    }
                    continue;
                case mapvalidated:
                    *userChoicePtr = ge.mapvalidatedFunc();
                    if (*userChoicePtr == "addplayer") {
                        *currentStatePtr = playeradded;
                    }
                    continue;
                case playeradded:
                    *userChoicePtr = ge.playeraddedFunc();
                    if (*userChoicePtr == "assigncountries") {
                        *currentStatePtr = assignreignforcement;
                    }
                    continue;
                case assignreignforcement:
                    *userChoicePtr = ge.assignreinforcementFunc();
                    if (*userChoicePtr == "issueorder") {
                        *currentStatePtr = issueorders;
                    }
                    continue;
                case issueorders:
                    *userChoicePtr = ge.issueordersFunc();
                    if (*userChoicePtr == "endissuorders") {
                        *currentStatePtr = executeorders;
                    }
                    continue;
                case executeorders:
                    *userChoicePtr = ge.executeordersFunc();
                    if (*userChoicePtr == "endexecorders") {
                        *currentStatePtr = assignreignforcement;
                    } else if (*userChoicePtr == "win") {
                        *currentStatePtr = win;
                    }
                    continue;
                case win:
                    *userChoicePtr = ge.winFunc();
                    if (*userChoicePtr == "play") {
                        *currentStatePtr = start;
                    } else if (*userChoicePtr == "end") {
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

