
#include <iostream>
#include <string>

#include "GameEngine.cpp"
using namespace std;


int main() {

    // Initialize gamestate at state and update upon state change
    GameState currentState = executeorders;
    GameState* currentStatePtr = &currentState;

    // Initializa game play boolean.
    bool play = true;
    bool* playPtr = &play;

    // Initialize var for keeping user's choice
    string userChoice;
    string* userChoicePtr = &userChoice;
    // while true keep the game playing.
    while(*playPtr) {
        switch (currentState) {
            case start:
                startState();
                *userChoicePtr = startState::startFunc();
                if (userChoice == "loadmap") {
                    *currentStatePtr = maploaded;
                }
            case maploaded:
                maploadedState();
                *userChoicePtr = maploadedState::maploadedFunc();
                if (userChoice == "validatemap") {
                    *currentStatePtr = mapvalidated;
                }
            case mapvalidated:
                mapvalidatedState();
                *userChoicePtr = mapvalidatedState::mapvalidatedFunc();
                if (userChoice == "addplayer") {
                    *currentStatePtr = playeradded;
                }
            case playeradded:
                playeraddedState();
                *userChoicePtr = playeraddedState::playeraddedFunc();
                if (userChoice == "assigncountries") {
                    *currentStatePtr = assignreignforcement;
                }
            case assignreignforcement:
                assignreinforcementState();
                *userChoicePtr = assignreinforcementState::assignreinforcementFunc();
                if (userChoice == "issueorder") {
                    *currentStatePtr = issueorder;
                }
            case issueorder:
                issueordersState();
                *userChoicePtr = issueordersState::issueordersFunc();
                if (userChoice == "endissuorders") {
                    *currentStatePtr = executeorders;
                }
            case executeorders:
                executeordersState();
                *userChoicePtr = executeordersState::executeordersFunc();
                if (userChoice == "endexecorders") {
                    *currentStatePtr = assignreignforcement;
                } else if (userChoice == "win") {
                    *currentStatePtr = win;
                }
            case win:
                winState();
                *userChoicePtr = winState::winFunc();
                if (userChoice == "play") {
                    *currentStatePtr = start;
                } else if (userChoice == "end") {
                    *playPtr = false;
                    break;
                }
            default:
                cout << "Invalid input";
        }
    }

    cout << "-------------------------------------";
    return 0;
}
