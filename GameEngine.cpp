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
        cout << "starting\n";
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
                cout << "Map validated\n";
                cout << "Moving to next state\n";
                break;
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
        cout << "map validated\n";
        cout << "Moving to the next state\n";
        return nextState;
    };
};