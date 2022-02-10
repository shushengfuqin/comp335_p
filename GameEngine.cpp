#include <iostream>
#include "GameEngine.h"

enum GameState {
    start, maploaded, mapvalidated, playeradded, assignreignforcement, issueorder, executeorders, win, quit
};
int userInput;
int* userInputPtr = &userInput;

string nextStateCmd;
string* nextStateCmdPtr = &nextStateCmd;
startState::startState() = default;
startState::~startState() = default;;

/**
 * This method takes the input of the user x
 * While the user does not chose 1 which is for the command loadmap,
 * The system will keep ask the use to input an valid command.
 * @return the command loadmap
 */
string startState::startFunc(){
        cout << "this is the start state\n";
        cout << "What would you like to do\n";
        cout << "Please chose action by typing the corresponding number\n";
        cout << "1- loadmap\n";
        cin >> *userInputPtr;
        while (*userInputPtr != 1){
            cout << "Please enter an valid command\n";
            cin >> *userInputPtr;
        }
        cout << "Moving to the next state\n";
        *nextStateCmdPtr = "loadmap";
        return *nextStateCmdPtr;
}



maploadedState::maploadedState() = default;
maploadedState::~maploadedState() = default;;
string maploadedState::maploadedFunc(){
        cout << "this is the map loaded state\n";
        cout << "What would you like to do\n";
        cout << "1 - load map\n";
        cout << "2 - validate map\n";
        cout << "Please chose action by typing the corresponding number\n";
        cin >> *userInputPtr;
        for(;;) {
            switch (*userInputPtr) {
                case 1:
                    cout << "map loaded again\n";
                    cout << "What would you like to do\n";
                    cout << "1 - load map\n";
                    cout << "2 - validate map\n";
                    cout << "Please chose action by typing the corresponding number\n";
                    cin >> *userInputPtr;
                    continue;
                case 2:
                    cout << "Moving to next state\n";
                    *nextStateCmdPtr = "validatemap";
                    return *nextStateCmdPtr;
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
                    continue;
            }
        }
    }


mapvalidatedState::mapvalidatedState()= default;;
mapvalidatedState::~mapvalidatedState()= default;;
string mapvalidatedState::mapvalidatedFunc(){
        string nextState;
        cout << "this is the map validated state\n";
        cout << "What would you like to do\n";
        cout << "1 - add player\n";
        cin >> *userInputPtr;
        while (*userInputPtr != 1){
            cout << "Please enter an valid command\n";
            cin >> *userInputPtr;
        }
        cout << "Moving to the next state\n";
        *nextStateCmdPtr = "addplayer";
        return *nextStateCmdPtr;
    };



playeraddedState::playeraddedState()= default;;
playeraddedState::~playeraddedState()= default;;
string playeraddedState::playeraddedFunc(){
        cout << "this is the player added state\n";
        cout << "What would you like to do\n";
        cout << "1 - add player\n";
        cout << "2 - assign countries\n";
        cout << "Please chose action by typing the corresponding number\n";
        cin >> *userInputPtr;
        for(;;){
            switch(*userInputPtr){
                case 1:
                    cout << "add player again\n";
                    cout << "What would you like to do\n";
                    cout << "1 - add player\n";
                    cout << "2 - assign countries\n";
                    cout << "Please chose action by typing the corresponding number\n";
                    cin >> *userInputPtr;
                    continue;
                case 2:
                    cout << "Moving to next state\n";
                    *nextStateCmdPtr = "assigncountries";
                    return *nextStateCmdPtr;
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
        }
};


assignreinforcementState::assignreinforcementState()= default;;
assignreinforcementState::~assignreinforcementState()= default;;
string assignreinforcementState::assignreinforcementFunc(){
        cout << "this is the assign reinforcement state\n";
        cout << "What would you like to do\n";
        cout << "1 - issue order\n";
        cout << "Please chose action by typing the corresponding number\n";
        cin >> *userInputPtr;
        while (*userInputPtr != 1){
            cout << "Please enter an valid command\n";
            cin >> *userInputPtr;
        }
        cout << "Moving to the next state\n";
        *nextStateCmdPtr = "issueorder";
        return *nextStateCmdPtr;
    };



issueordersState::issueordersState()= default;;
issueordersState::~issueordersState()= default;;
string issueordersState::issueordersFunc(){
        cout << "this is the issue order state\n";
        cout << "What would you like to do\n";
        cout << "1 - issue order\n";
        cout << "2 - end issue orders\n";
        cout << "Please chose action by typing the corresponding number\n";
        cin >> *userInputPtr;
        for(;;){
            switch(*userInputPtr){
                case 1:
                    cout << "issue order again\n";
                    cout << "What would you like to do\n";
                    cout << "1 - issue order\n";
                    cout << "2 - end issue orders\n";
                    cout << "Please chose action by typing the corresponding number\n";
                    cin >> *userInputPtr;
                    continue;
                case 2:
                    cout << "Moving to next state\n";
                    *nextStateCmdPtr = "endissuorders";
                    return *nextStateCmdPtr;
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
        }
    };



executeordersState::executeordersState()= default;;
executeordersState::~executeordersState()= default;;
string executeordersState::executeordersFunc(){
        cout << "this is the execute order state\n";
        cout << "What would you like to do\n";
        cout << "1 - execute order\n";
        cout << "2 - end execute order orders\n";
        cout << "3 - win\n";
        cout << "Please chose action by typing the corresponding number\n";
        cin >> *userInputPtr;
        for(;;) {
            switch (*userInputPtr) {
                case 1:
                    cout << "execute order again\n";
                    cout << "What would you like to do\n";
                    cout << "1 - execute order\n";
                    cout << "2 - end execute orders\n";
                    cout << "3 - win\n";
                    cout << "Please chose action by typing the corresponding number\n";
                    cin >> *userInputPtr;
                    continue;
                case 2:
                    cout << "Moving to assign reinforcement state\n";
                    *nextStateCmdPtr = "endexecorders";
                    break;
                case 3:
                    cout << "Moving to win state\n";
                    *nextStateCmdPtr = "win";
                    break;
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
            return *nextStateCmdPtr;
        }
    };



winState::winState()= default;;
winState::~winState()= default;;
string winState::winFunc(){
        cout << "this is the win state\n";
        cout << "What would you like to do\n";
        cout << "1 - end\n";
        cout << "2 - play again\n";
        cout << "Please chose action by typing the corresponding number\n";
        cin >> *userInputPtr;
        for(;;) {
            switch (*userInputPtr) {
                case 1:
                    cout << "Thank you for playing. See you next time\n";
                    *nextStateCmdPtr = "end";
                    break;
                case 2:
                    cout << "Moving to Start state\n";
                    *nextStateCmdPtr = "play";
                    break;
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
            return *nextStateCmdPtr;
        }
    };
