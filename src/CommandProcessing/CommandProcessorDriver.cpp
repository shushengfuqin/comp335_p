
#include <iostream>
#include <string>

#include "../GameEngine/GameEngine.h"


using namespace std;

class CommandProcessorDriver{
public:
    CommandProcessorDriver()= default;
    ~CommandProcessorDriver()= default;
    static void callCommandProcessorDriver(bool readFromFile, bool tournamentMode, const string& filename, const string& tournamentCmd) {

        // Initializa game play boolean.
        bool play = true;
        bool* playPtr = &play;

        // Initialize var for keeping user's choice
        string userChoice;
        string* userChoicePtr = &userChoice;

        // Initialize logObserver
        auto* logObserver = new LogObserver();
        auto* cp = new CommandProcessor();

        // Unique adapter for file reading
        if(readFromFile){
            auto * flr = new FileLineReader(filename);
            cp = new FileCommandProcessorAdapter(flr);
        }
        // Add tournament command as first command
        else if(tournamentMode)
            cp = new CommandProcessor(tournamentCmd);
        else
            cp = new CommandProcessor();

        auto* gameState = new GameEng(cp);
        GameEng ge = *gameState;

        // Regular game
        if(!tournamentMode)
            ge.setState(start);
        // Tournament mode
        else
            ge.setState(tournament);

        // while true keep the game playing.
        while(*playPtr) {
            switch (ge.getState()) {
                case start:{
                    ge.startUpPhase();
                    // Changed to Tournament Mode
                    if(ge.getState() == tournament)
                        ge.tournamentGameLoop();
                    else
                        ge.mainGameLoop();
                    break;
                }
                case tournament:{
                    ge.startUpPhase();
                    ge.tournamentGameLoop();
                    break;
                }
                case win:
                    *userChoicePtr = ge.winFunc();
                    if (*userChoicePtr == "replay") {
                        ge.Transition();
                        ge.setState(start);
                    } else if (*userChoicePtr == "quit") {
                        // since the user chose to quit, therefore, change the bool to play false, to close.
                        ge.Transition();
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


