#include <iostream>
#include "GameEngine.h"

enum GameState {
    start, maploaded, mapvalidated, playeradded, assignreignforcement, issueorder, executeorders, win
};

/**
 * userInput will save the cmd of the user.
 */
int userInput;
int* userInputPtr = &userInput;

startState::startState() = default;
startState::~startState() = default;

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command loadmap,
 * The system will keep ask the use to input an valid command.
 * @return the command loadmap
 */
string startState::startFunc(){
        cout << "this is the start state\n";
        cout << "What would you like to do\n";
        cout << "1- loadmap\n";
        cout << "Please chose action by typing the corresponding number\n";
        cin >> *userInputPtr;
        while (*userInputPtr != 1){
            cout << "Please enter an valid command\n";
            cin >> *userInputPtr;
        }
        cout << "Moving to the next state\n";
        return "loadmap";
}



maploadedState::maploadedState() = default;
maploadedState::~maploadedState() = default;

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd loadmap.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "validatemap"
 */
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
                    return "validatemap";
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
                    continue;
            }
        }
    }


mapvalidatedState::mapvalidatedState()= default;
mapvalidatedState::~mapvalidatedState()= default;

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command addplayer,
 * The system will keep ask the use to input an valid command.
 * @return "addplayer"
 */
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
        return "addplayer";
    }



playeraddedState::playeraddedState()= default;
playeraddedState::~playeraddedState()= default;

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd addplayer.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "assigncountries"
 */
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
                    return "assigncountries";
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
        }
}


assignreinforcementState::assignreinforcementState()= default;
assignreinforcementState::~assignreinforcementState()= default;

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command addplayer,
 * The system will keep ask the use to input an valid command.
 * @return "issueorder"
 */
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
        return "issueorder";
    }



issueordersState::issueordersState()= default;
issueordersState::~issueordersState()= default;

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd issueorder.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "endissuorders"
 */
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
                    return "endissuorders";
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
        }
    }



executeordersState::executeordersState()= default;
executeordersState::~executeordersState()= default;

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd execute order.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "endexecorders" or "win"
 */
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
                    return "endexecorders";
                case 3:
                    cout << "Moving to win state\n";
                    return "win";
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
        }

    }



winState::winState()= default;
winState::~winState()= default;

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep choosing an invalid cmd
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "end" or "play"
 */
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
                    return "end";
                case 2:
                    cout << "Moving to Start state\n";
                    return "play";
                default:
                    cout << "Please enter a valid input\n";
                    cin >> *userInputPtr;
            }

        }
    }
