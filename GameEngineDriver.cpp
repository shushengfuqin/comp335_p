
#include <iostream>
#include <string>

#include "GameEngine.cpp"
using namespace std;


int main() {

    // Initialize gamestate at state and update upon state change
    GameState currentState = start;
    GameState* currentStatePtr = &currentState;

    // Initializa game play boolean.
    bool play = true;
    bool* playPtr = &play;
    while(*playPtr) {
        switch (currentState) {
            case start:
                startState();
                if (startState::startFunc() == "loadmap") {
                    *currentStatePtr = maploaded;
                }
                continue;
            case maploaded:
                maploadedState();
                if (maploadedState::maploadedFunc() == "validatemap") {
                    *currentStatePtr = mapvalidated;
                }
                continue;
            case mapvalidated:
                mapvalidatedState();
                if (mapvalidatedState::mapvalidatedFunc() == "addplayer") {
                    *currentStatePtr = playeradded;
                }
                continue;
            case playeradded:
                playeraddedState();
                if (playeraddedState::playeraddedFunc() == "assigncountries") {
                    *currentStatePtr = assignreignforcement;
                }
                continue;
            case assignreignforcement:
                assignreinforcementState();
                if (assignreinforcementState::assignreinforcementFunc() == "issueorder") {
                    *currentStatePtr = issueorder;
                }
                continue;
            case issueorder:
                issueordersState();
                if (issueordersState::issueordersFunc() == "endissuorders") {
                    *currentStatePtr = executeorders;
                }
                continue;
            case executeorders:
                executeordersState();
                if (executeordersState::executeordersFunc() == "endexecorders") {
                    *currentStatePtr = assignreignforcement;
                } else if (executeordersState::executeordersFunc() == "win") {
                    *currentStatePtr = win;
                }
                continue;
            case win:
                winState();
                if (winState::winFunc() == "end") {
                    *currentStatePtr = quit;
                } else if (winState::winFunc() == "play") {
                    *currentStatePtr = start;
                }
                continue;
            case quit:
                *playPtr = false;
                break;
            default:
                cout << "Invalid input";
        }
    }
    return 0;
}
