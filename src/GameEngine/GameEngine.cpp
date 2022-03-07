#include "GameEngine.h"
#include <iostream>
#include <regex>

/**
 * Why input int instead of string.
 * The user input and define action is using an switch case statement. It is more clear and easy then if statements.
 * However, in cpp, the switch case evaluate only int.
 * It is possible to use enum for the different transition cmd. However the cmd are overlapping with the state.
 * Which create confusion in the convention.
 */

/**
 * userInput will save the cmd of the user.
 */
int userInput;
regex loadRegex ("loadmap\\s.+");
regex playerRegex("addplayer\\s.+");


GameEng::GameEng() {
    cmdProc = new CommandProcessor();
}

GameEng::GameEng(CommandProcessor * cp) {
    cmdProc = cp;
}

GameEng::GameEng(FileLineReader *flr) {
    cmdProc = new FileCommandProcessorAdapter(flr);
}

GameEng::~GameEng() = default;

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command loadmap,
 * The system will keep ask the use to input an valid command.
 * @return the command loadmap
 */

string GameEng::startFunc()
{
    cout << "this is the start state\n";
    cout << "1 - loadmap <mapfile>\n";
    cmdProc->getCommand();
    while (!regex_match (cmdProc->validate(getState()), loadRegex))
    {
        cout << "Error: Please enter an valid command\n";
        cmdProc->getCommand();
    }

    // *** LOAD MAP HERE ***

    cout << "Moving to the next state\n";
    Notify(this);

    return "loadmap";
}

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd loadmap.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "validatemap"
 */
string GameEng::maploadedFunc()
{
    cout << "this is the map loaded state\n";
    cout << "1 - loadmap <mapfile>\n";
    cout << "2 - validatemap\n";
    cmdProc->getCommand();

    for (;;)
    {
        string cmdInput = cmdProc->validate(getState());

        if(regex_match (cmdInput, loadRegex)){
            cout << "map loaded again\n";
            cout << "1 - loadmap <mapfile>\n";
            cout << "2 - validatemap\n";
            cmdProc->getCommand();
            Notify(this);
            continue;
        }
        else if(cmdInput == "validatemap"){
            cout << "Moving to next state\n";
            Notify(this);

            // *** VALIDATE MAP HERE ***

            return "validatemap";
        }
        else{
            cout << "Error: Please enter a valid input\n";
            cmdProc->getCommand();
            Notify(this);
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
string GameEng::mapvalidatedFunc()
{
    string nextState;
    cout << "this is the map validated state\n";
    cout << "1 - addplayer <playername> \n";
    cmdProc->getCommand();
    while (!regex_match (cmdProc->validate(getState()), playerRegex))
    {
        cout << "Error: Please enter an valid command\n";
        cmdProc->getCommand();
    }
    cout << "Moving to the next state\n";
    Notify(this);

    // *** ADD PLAYER HERE ***

    return "addplayer";
}

/**
 * This method takes the input of the user
 * using a for loop which allows the user to keep chosing the cmd addplayer.
 * With the switch case to allow user to break out and return the cmd to switch to the next step
 * The system will keep ask the use to input an valid command.
 * @return string "assigncountries"
 */
string GameEng::playeraddedFunc()
{
    cout << "this is the player added state\n";
    cout << "1 - addplayer <playername> \n";
    cout << "2 - gamestart\n";
    cmdProc->getCommand();
    for (;;)
    {
        string cmdInput = cmdProc->validate(getState());

        if(regex_match (cmdInput, playerRegex)){
            cout << "add player again\n";
            cout << "1 - addplayer <playername>\n";
            cout << "2 - gamestart\n";
            cmdProc->getCommand();
            Notify(this);

            // *** ADD PLAYER HERE ***

            continue;
        }
        else if(cmdInput == "gamestart"){
            cout << "Moving to next state\n";
            Notify(this);

            // *** START GAME HERE ***

            return "assigncountries";
        }
        else{
            cout << "Error: Please enter a valid input\n";
            cmdProc->getCommand();
            Notify(this);
            continue;
        }
    }
}

/**
 * This method takes the input of the user
 * While the user does not chose 1 which is for the command addplayer,
 * The system will keep ask the use to input an valid command.
 * @return "issueorder"
 */
string GameEng::assignreinforcementFunc()
{
    cout << "this is the assign reinforcement state\n";
    cout << "What would you like to do\n";
    cout << "1 - issue order\n";
    cout << "Please chose action by typing the corresponding number\n";
    cin >> userInput;
    while (userInput != 1)
    {
        cout << "Error: Please enter an valid command\n";
        cin >> userInput;
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
string GameEng::issueordersFunc()
{
    cout << "this is the issue order state\n";
    cout << "What would you like to do\n";
    cout << "1 - issue order\n";
    cout << "2 - end issue orders\n";
    cout << "Please chose action by typing the corresponding number\n";
    cin >> userInput;
    for (;;)
    {
        switch (userInput)
        {
        case 1:
            cout << "issue order again\n";
            cout << "What would you like to do\n";
            cout << "1 - issue order\n";
            cout << "2 - end issue orders\n";
            cout << "Please chose action by typing the corresponding number\n";
            cin >> userInput;
            continue;
        case 2:
            cout << "Moving to next state\n";
            return "endissuorders";
        default:
            cout << "Error: Please enter a valid input\n";
            cin >> userInput;
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
string GameEng::executeordersFunc()
{
    cout << "this is the execute order state\n";
    cout << "What would you like to do\n";
    cout << "1 - execute order\n";
    cout << "2 - end execute order\n";
    cout << "3 - win\n";
    cout << "Please chose action by typing the corresponding number\n";
    cin >> userInput;
    for (;;)
    {
        switch (userInput)
        {
        case 1:
            cout << "execute order again\n";
            cout << "What would you like to do\n";
            cout << "1 - execute order\n";
            cout << "2 - end execute orders\n";
            cout << "3 - win\n";
            cout << "Please chose action by typing the corresponding number\n";
            cin >> userInput;
            continue;
        case 2:
            cout << "Moving to assign reinforcement state\n";
            return "endexecorders";
        case 3:
            cout << "Moving to win state\n";
            return "win";
        default:
            cout << "Error: Please enter a valid input\n";
            cin >> userInput;
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
string GameEng::winFunc()
{
    cout << "this is the win state\n";
    cout << "1 - replay\n";
    cout << "2 - quit\n";
    cmdProc->getCommand();
    for (;;)
    {
        string cmdInput = cmdProc->validate(getState());

        if(cmdInput == "replay"){
            cout << "Moving to next state\n";
            Notify(this);
            return "replay";
        }
        else if(cmdInput == "quit"){
            cout << "Thank you for playing. See you next time\n";
            Notify(this);
            return "quit";
        }
        else{
            cout << "Error: Please enter a valid input\n";
            cmdProc->getCommand();
            Notify(this);
            continue;
        }
    }

}

void GameEng::startUpPhase() {
    // Continue until start up phase is complete
    while(getState() != win && getState() != assignreignforcement){
        switch (getState()) {
            case start:
                if (startFunc() == "loadmap") {
                    setState(maploaded);
                }
            case maploaded:
                if (maploadedFunc() == "validatemap") {
                    setState(mapvalidated);
                }
            case mapvalidated:
                if (mapvalidatedFunc() == "addplayer") {
                    setState(playeradded);
                }
            case playeradded:
                if (playeraddedFunc() == "assigncountries") {
                    setState(win);
                }
            default:
                break;
        }
    }


}

string GameEng::stringToLog() {
    return "Game Engine user enter: ";
}
