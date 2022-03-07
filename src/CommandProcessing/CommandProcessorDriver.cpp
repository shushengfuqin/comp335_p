
#include <iostream>
#include <string>

#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameState.h"

using namespace std;

class CommandProcessorDriver{
public:
    CommandProcessorDriver()= default;
    ~CommandProcessorDriver()= default;
    static void callCommandProcessorDriver(bool readFromFile, string filename) {

        // Initialize gamestate at state and update upon state change
        //GameState currentState = start;
        //GameState* currentStatePtr = &currentState;

        // Initializa game play boolean.
        bool play = true;
        bool* playPtr = &play;

        // Initialize var for keeping user's choice
        string userChoice;
        string* userChoicePtr = &userChoice;

        // Initialize logObserver
        LogObserver* logObserver = new LogObserver();
        CommandProcessor* cp = new CommandProcessor();

        if(readFromFile){
            //filename = "C:\\Users\\Scrib\\Documents\\GitHub\\comp345_p\\src\\CommandProcessing\\commands.txt";
            FileLineReader * flr = new FileLineReader(filename);
            cp = new FileCommandProcessorAdapter(flr);
        }
        else
            cp = new CommandProcessor();

        cp->Attach(logObserver);
        GameEng* gameState = new GameEng(cp);
        GameEng ge = *gameState;
        ge.Attach(logObserver);
        ge.setState(start);

        // while true keep the game playing.
        while(*playPtr) {
            switch (ge.getState()) {
                case start:
                    ge.startUpPhase();
                /*case start:
                    *userChoicePtr = ge.startFunc();
                    if (userChoice == "loadmap") {
                        ge.setState(maploaded);
                    }
                case maploaded:
                    *userChoicePtr = ge.maploadedFunc();
                    if (userChoice == "validatemap") {
                        ge.setState(mapvalidated);
                    }
                case mapvalidated:
                    *userChoicePtr = ge.mapvalidatedFunc();
                    if (userChoice == "addplayer") {
                        ge.setState(playeradded);
                    }
                case playeradded:
                    *userChoicePtr = ge.playeraddedFunc();
                    if (userChoice == "assigncountries") {
                        ge.setState(win);
                    }
                case playeradded:
                    *userChoicePtr = ge.playeraddedFunc();
                    if (userChoice == "gamestart") {
                        ge.setState(assignreignforcement);
                    }
                case assignreignforcement:
                    *userChoicePtr = ge.assignreinforcementFunc();
                    if (userChoice == "issueorder") {
                        ge.setState(issueorders);
                    }
                case issueorders:
                    *userChoicePtr = ge.issueordersFunc();
                    if (userChoice == "endissuorders") {
                        ge.setState(executeorders);
                    }
                case executeorders:
                    *userChoicePtr = ge.executeordersFunc();
                    if (userChoice == "endexecorders") {
                        ge.setState(assignreignforcement);
                    } else if (userChoice == "win") {
                        ge.setState(win);
                    }
                */
                case win:
                    *userChoicePtr = ge.winFunc();
                    if (userChoice == "replay") {
                        ge.setState(start);
                    } else if (userChoice == "quit") {
                        // since the user chose to quit, therefore, change the bool to play false, to close.
                        *playPtr = false;
                        break;
                    }
                    continue;
                default:
                    cout << "Error: Invalid input\n";
            }
        }
    }
};


