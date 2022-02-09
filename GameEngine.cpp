#include <iostream>

using namespace std;

enum GameState {
    start, maploaded, mapvalidated, playeradded, assignreignforcement, issueorder, executeorders,win, quit
};

class startState{
public:
    startState()= default;;
    ~startState()= default;;
    static string startFunc(){
        string nextState = "changeState";
        cout << "this is the start state\n";
        cout << "What would you like to do\n";
        cout << "1- loadmap\n";
        int x;
        cin >> x;
        while (x != 1){
            cout << "Please enter an valid command\n";
            cin >> x;
        }
        cout << "Moving to the next state\n";
        return nextState;
    };

};

class maploadedState{
public:
    maploadedState()= default;;
    ~maploadedState()= default;;
    static string maploadedFunc(){
        string nextState = "changeState";
        cout << "this is the map loaded state\n";
        cout << "What would you like to do\n";
        cout << "1 - load map\n";
        cout << "2 - validate map\n";
        cout << "Please chose action by typing the corresponding number\n";
        int x;
        cin >> x;

        switch(x){
            case 1:
                cout << "map loaded again\n";
                cout << "What would you like to do\n";
                cout << "1 - load map\n";
                cout << "2 - validate map\n";
                cout << "Please chose action by typing the corresponding number\n";
                cin >> x;
            case 2:
                cout << "Moving to next state\n";
                return nextState;
            default:
                cout << "Please enter a valid input\n";
                cin >> x;
        }
    };
};

class mapvalidatedState{
public:
    mapvalidatedState()= default;;
    ~mapvalidatedState()= default;;
    static string mapvalidatedFunc(){
        string nextState;
        cout << "this is the map validated state\n";
        cout << "What would you like to do\n";
        cout << "1 - add player\n";
        int x;
        cin >> x;
        while (x != 1){
            cout << "Please enter an valid command\n";
        }
        cout << "Moving to the next state\n";
        return nextState;
    };
};

class playeraddedState{
public:
    playeraddedState()= default;;
    ~playeraddedState()= default;;
    static string playeraddedFunc(){
        string nextState = "changeState";
        cout << "this is the player added state\n";
        cout << "What would you like to do\n";
        cout << "1 - add player\n";
        cout << "2 - assign countries\n";
        cout << "Please chose action by typing the corresponding number\n";
        int x;
        cin >> x;

        switch(x){
            case 1:
                cout << "add player again\n";
                cout << "What would you like to do\n";
                cout << "1 - add player\n";
                cout << "2 - assign countries\n";
                cout << "Please chose action by typing the corresponding number\n";
                cin >> x;
            case 2:
                cout << "Moving to next state\n";
                return nextState;
            default:
                cout << "Please enter a valid input\n";
                cin >> x;
        }
    };
};

class assignreinforcementState{
public:
    assignreinforcementState()= default;;
    ~assignreinforcementState()= default;;
    static string assignreinforcementFunc(){
        string nextState = "changeState";
        cout << "this is the assign reinforcement state\n";
        cout << "What would you like to do\n";
        cout << "1 - issue order\n";
        cout << "Please chose action by typing the corresponding number\n";
        int x;
        cin >> x;
        while (x != 1){
            cout << "Please enter an valid command\n";
        }
        cout << "Moving to the next state\n";
        return nextState;
    };
};

class issueordersState{
public:
    issueordersState()= default;;
    ~issueordersState()= default;;
    static string issueordersFunc(){
        string nextState = "changeState";
        cout << "this is the issue order state\n";
        cout << "What would you like to do\n";
        cout << "1 - issue order\n";
        cout << "2 - end issue orders\n";
        cout << "Please chose action by typing the corresponding number\n";
        int x;
        cin >> x;

        switch(x){
            case 1:
                cout << "issue order again\n";
                cout << "What would you like to do\n";
                cout << "1 - issue order\n";
                cout << "2 - end issue orders\n";
                cout << "Please chose action by typing the corresponding number\n";
                cin >> x;
            case 2:
                cout << "Moving to next state\n";
                return nextState;
            default:
                cout << "Please enter a valid input\n";
                cin >> x;
        }
    };
};

class executeordersState{
public:
    executeordersState()= default;;
    ~executeordersState()= default;;
    static string executeordersFunc(){
        cout << "this is the execute order state\n";
        cout << "What would you like to do\n";
        cout << "1 - execute order\n";
        cout << "2 - end execute order orders\n";
        cout << "3 - win\n";
        cout << "Please chose action by typing the corresponding number\n";
        int x;
        cin >> x;

        switch(x){
            case 1:
                cout << "execute order again\n";
                cout << "What would you like to do\n";
                cout << "1 - execute order\n";
                cout << "2 - end execute orders\n";
                cout << "3 - win\n";
                cout << "Please chose action by typing the corresponding number\n";
                cin >> x;
            case 2:
                cout << "Moving to assign reinforcement state\n";
                return "2";
            case 3:
                cout << "Moving to win state";
                return "3";
            default:
                cout << "Please enter a valid input\n";
                cin >> x;
        }
    };
};

class winState{
public:
    winState()= default;;
    ~winState()= default;;
    static int winFunc(){
        cout << "this is the win state\n";
        cout << "What would you like to do\n";
        cout << "1 - end\n";
        cout << "2 - play again\n";
        cout << "Please chose action by typing the corresponding number\n";
        int x;
        cin >> x;

        switch(x){
            case 1:
                cout << "Thank you for playing. See you next time\n";
                return 1;
            case 2:
                cout << "Moving to Start state\n";
                return 2;
            default:
                cout << "Please enter a valid input\n";
                cin >> x;
        }
    };
};