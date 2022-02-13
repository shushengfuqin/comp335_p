#include <iostream>
#include "GameEngine.h"
/**
 * Why input int instead of string.
 * The user input and define action is using an switch case statement. It is more clear and easy then if statements.
 * However, in cpp, the switch case evaluate only int.
 * It is possible to use enum for the different transition cmd. However the cmd are overlapping with the state.
 * Which create confusion in the convention.
 */
enum GameState {
    start, maploaded, mapvalidated, playeradded, assignreignforcement, issueorders, executeorders, win
};


/**
 * userInput will save the cmd of the user.
 */
int userInput;
int* userInputPtr = &userInput;



GameEngine::GameEngine()= default;
GameEngine::~GameEngine()= default;


/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command loadmap,
 * The system will keep ask the use to input an valid command.
 * @return the command loadmap
 */

string GameEngine::startFunc(){
        cout << "this is the start state\n";
        cout << "What would you like to do\n";
        cout << "1 - loadmap\n";
        cout << "Please chose action by typing the corresponding command\n";
        cin >> *userInputPtr;
        while (*userInputPtr != 1){
            cout << "Error: Please enter an valid command\n";
            cin >> *userInputPtr;
        }
        cout << "Moving to the next state\n";
        return "loadmap";
}

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd loadmap.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "validatemap"
 */
string GameEngine::maploadedFunc(){
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
                cout << "Error: Please enter a valid input\n";
                cin >> *userInputPtr;
                continue;
        }
    }
}

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command addplayer,
 * The system will keep ask the use to input an valid command.
 * @return "addplayer"
 */
string GameEngine::mapvalidatedFunc(){
        string nextState;
        cout << "this is the map validated state\n";
        cout << "What would you like to do\n";
        cout << "1 - add player\n";
        cin >> *userInputPtr;
        while (*userInputPtr != 1){
            cout << "Error: Please enter an valid command\n";
            cin >> *userInputPtr;
        }
        cout << "Moving to the next state\n";
        return "addplayer";
    }

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd addplayer.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "assigncountries"
 */
string GameEngine::playeraddedFunc(){
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
                    cout << "Error: Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
        }
}

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command addplayer,
 * The system will keep ask the use to input an valid command.
 * @return "issueorder"
 */
string GameEngine::assignreinforcementFunc(){
        cout << "this is the assign reinforcement state\n";
        cout << "What would you like to do\n";
        cout << "1 - issue order\n";
        cout << "Please chose action by typing the corresponding number\n";
        cin >> *userInputPtr;
        while (*userInputPtr != 1){
            cout << "Error: Please enter an valid command\n";
            cin >> *userInputPtr;
        }
        cout << "Moving to the next state\n";
        return "issueorder";
    }

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd issueorder.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "endissuorders"
 */
string GameEngine::issueordersFunc(){
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
                    cout << "Error: Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
        }
    }

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd execute order.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "endexecorders" or "win"
 */
string GameEngine::executeordersFunc(){
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
                    cout << "Error: Please enter a valid input\n";
                    cin >> *userInputPtr;
            }
        }

    }



/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep choosing an invalid cmd
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "end" or "play"
 */
string GameEngine::winFunc(){
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
                    cout << "Error: Please enter a valid input\n";
                    cin >> *userInputPtr;
            }

        }
    }
