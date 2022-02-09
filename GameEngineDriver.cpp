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
            break;
        case playeradded:
            break;
        case assignreignforcement:
            break;
        case issueorder:
            break;
        case executeorders:
            break;
        case win:
            break;
        case quit:
            break;
        default:
            cout << "Invalid input";
    };
    return 0;
}
