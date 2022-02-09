#include <iostream>
#include <string>

#include "GameEngine.cpp"
using namespace std;


int main() {

    // Initialize gamestate at state and update upon state change
    GameState currentState = start;
    //constructor for each state class
    switch(currentState){
        case start:
            startState();
            if (startState::startFunc() == "changeState"){
                currentState = maploaded;
            }
        case maploaded:
            maploadedState();
            if (maploadedState::maploadedFunc() == "changeState"){
                currentState = mapvalidated;
            }
        case mapvalidated:
            mapvalidatedState();
            if (mapvalidatedState::mapvalidatedFunc() == "changeState"){
                currentState = playeradded;
            }
        case playeradded:
            playeraddedState();
            if (playeraddedState::playeraddedFunc() == "changeState"){
                currentState = assignreignforcement;
            }
        case assignreignforcement:
            assignreinforcementState();
            if (assignreinforcementState::assignreinforcementFunc() == "changeState"){
                currentState = issueorder;
            }
        case issueorder:
            issueordersState();
            if (issueordersState::issueordersFunc() == "changeState"){
                currentState = executeorders;
            }
        case executeorders:
            executeordersState();
            if (executeordersState::executeordersFunc() == "2"){
                currentState = assignreignforcement;
            } else if (executeordersState::executeordersFunc() == "3"){
                currentState = win;
            }
        case win:
            winState();
            if (winState::winFunc() == 1){
                currentState = quit;
            } else if (winState::winFunc() == 2){
                currentState = start;
            }
        case quit:
            break;
        default:
            cout << "Invalid input";
    };
    return 0;
}
