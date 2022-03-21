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
    userCmd = cmdProc->validate(getState());
    while (!regex_match (userCmd, loadRegex))
    {
        cout << "Error: Please enter an valid command\n";
        cmdProc->getCommand();
        userCmd = cmdProc->validate(getState());
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
string GameEng::maploadedFunc()
{
    cout << "this is the map loaded state\n";
    cout << "1 - loadmap <mapfile>\n";
    cout << "2 - validatemap\n";
    cmdProc->getCommand();

    for (;;)
    {
        userCmd = cmdProc->validate(getState());

        if(regex_match (userCmd, loadRegex)){
            cout << "map loaded again\n";
            cout << "1 - loadmap <mapfile>\n";
            cout << "2 - validatemap\n";
            cmdProc->getCommand();
            continue;
        }
        else if(userCmd == "validatemap"){
            cout << "Moving to next state\n";
            return "validatemap";
        }
        else{
            cout << "Error: Please enter a valid input\n";
            cmdProc->getCommand();
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
    userCmd = cmdProc->validate(getState());
    while (!regex_match (userCmd, playerRegex))
    {
        cout << "Error: Please enter an valid command\n";
        cmdProc->getCommand();
        userCmd = cmdProc->validate(getState());
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
string GameEng::playeraddedFunc()
{
    cout << "this is the player added state\n";
    cout << "1 - addplayer <playername> \n";
    cout << "2 - gamestart\n";
    cmdProc->getCommand();
    for (;;)
    {
        userCmd = cmdProc->validate(getState());

        if(regex_match (userCmd, playerRegex)){
            cout << "add player again\n";
            cout << "1 - addplayer <playername>\n";
            cout << "2 - gamestart\n";
            cmdProc->getCommand();
            continue;
        }
        else if(userCmd == "gamestart"){
            cout << "Moving to next state\n";
            return "assigncountries";
        }
        else{
            cout << "Error: Please enter a valid input\n";
            cmdProc->getCommand();
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
        userCmd = cmdProc->validate(getState());

        if(userCmd == "replay"){
            cout << "Moving to next state\n";
            return "replay";
        }
        else if(userCmd == "quit"){
            cout << "Thank you for playing. See you next time\n";
            return "quit";
        }
        else{
            cout << "Error: Please enter a valid input\n";
            cmdProc->getCommand();
            continue;
        }
    }
}

void GameEng::Transition(){
    Notify(this);
}

string GameEng::stringToLog() {
    return "Game Engine: " + userCmd;
}

/**
 * This function checks the amount of reinforcement that each player gets and set it in to their reinforcement num.
 * @param playerList
 */
void GameEng::reinforcementPhase(vector<Player*> playerList){
    // temp for that player's reinforcementNum
    int temp = 0;

    // get the num of territory that player has
    int ter_count = 0;

    // bool check if that player has continent bonus
    bool check = false;

    // the bonus that the player get from continent bonus
    int bonus = 0;

    // 1. for each player in the vector
    for(int i = 0; i < playerList.size(), i++){
        // get the ammount of reinforcement for that player
        temp = playerList[i]->getReinforcementPool();

        // get the amount of territory of that player
        for(int j = 0; j< playList[i]->territory.size(); j++){
            ter_count++;
        }

        // calculate the continent bonus of the that player
        check = playerList[i].continentBonus();
        bonus = getBonus();

        // according to the bonus that the player has, the amount of reignforcement the player has
        if(check){
            temp += bonus + (int)round(ter_count/3);
        } else {
            temp += (int)round(ter_count / 3);
        }

        playerList[i]->setReinforcement(temp);
        temp = 0;
        check = false;
        bonus = 0;
        ter_count = 0;
    }

}

/**
 * Each player make an order and add it into the orderList.
 * If the order is to play a card, if will first call the function to play a card in hand
 * Player who still have reinforcement in the pool, can only deploy.
 */
void GameEng::issueOrderPhase(vector<Player*> playerList){
// first it is round robin style of passing through the players
    for(int i = 0; i < playerList.size(), i++){
        // check if that players reinforcement is greater than 0
        if(playerList[i])
    }
}

