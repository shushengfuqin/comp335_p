
#include <iostream>
#include <string>
#include "./src/Cards/CardsDriver.cpp"
#include "src/Order/OrdersDriver.cpp"
#include "src/GameEngine/GameEngineDriver.cpp"
#include "src/Map/MapDriver.cpp"
#include "src/Player/PlayerDriver.cpp"
#include "src/CommandProcessing/CommandProcessorDriver.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    CommandProcessorDriver cpd;

    string maps[5];
    string players[4];
    string games;
    string turns;
    int index = 2;
    int count = 0;

    // parameters
    if (argc > 1){
        if(std::string(argv[1]) == "-file")
            cpd.callCommandProcessorDriver(true, false, argv[2], "");
        else if(std::string(argv[1]) == "-M"){
            /// COMMAND LINE VALIDATION
            /// MAP VALIDATION
            // Take at most 5 maps
            while(std::string(argv[index]) != "-P"){
                // Too many maps given
                if(count >= 5){
                    cout << "Invalid parameters entered: Too many maps given." << endl;
                    exit(0);
                }

                maps[count] = std::string(argv[index]);
                count++;
                index++;
            }
            // No maps given
            if(count == 0){
                cout << "Invalid parameters entered: No maps given." << endl;
                exit(0);
            }

            /// PLAYER VALIDATION
            count = 0;  // Reset count
            index++;    // Move past "-P"
            // Take at most 4 players
            while(std::string(argv[index]) != "-G"){
                // Too many maps given
                if(count >= 4){
                    cout << "Invalid parameters entered: Too many players given." << endl;
                    exit(0);
                }

                players[count] = std::string(argv[index]);
                count++;
                index++;
            }
            // Too little players given
            if(count < 2){
                cout << "Invalid parameters entered: Too little players given." << endl;
                exit(0);
            }

            /// GAMES VALIDATION
            index++;    // Move past "-G"
            if(atoi(argv[index]) >= 1 && atoi(argv[index]) <= 4){
                games = argv[index];
                index++;
            }
            else{
                cout << "Invalid parameters entered: Invalid number of games." << endl;
                exit(0);
            }

            /// TURNS VALIDATION
            if(std::string(argv[index]) != "-D"){
                cout << "Invalid parameters entered: Too many parameters for number of games." << endl;
                exit(0);
            }
            index++;    // Move past "-D"
            if(atoi(argv[index]) >= 10 && atoi(argv[index]) <= 50){
                turns = argv[index];
            }

            //////////

            // Testing that all parameters were read
            // Recreate full command
            string tCmd = "tournament ";
            tCmd += "-M ";
            for(int i = 0; i < 5; i++){
                if(maps[i] != "")
                    tCmd += maps[i] + " ";
            }
            tCmd += "-P ";
            for(int i = 0; i < 4; i++){
                if(players[i] != "")
                    tCmd += players[i] + " ";
            }
            tCmd += "-G " + games + " ";
            tCmd += "-D " + turns;

            cpd.callCommandProcessorDriver(false, true, "", tCmd);
        }
        else{
            cout << "Invalid parameters entered." << endl;
            exit(0);
        }
    }
    // console (default)
    else
        cpd.callCommandProcessorDriver(false, false, "", "");



//string x;
//
//    cout << "------------- ORDER DRIVER CLASS ----------------\n";
//    OrdersDriver od;
//    od.callOrdersDriver();
//    cout << "Going to the next one please enter Y\n";
//    cin >> x;
//    cout << "\n";
//
//
//    if(x == "y"){
//        cout << "------------- CARDS DRIVER CLASS ----------------\n";
//        CardsDriver cd;
//        cd.callCardsDriver();
//    }
//
//    cout << "\n";
//    cout << "Going to the next one please enter Y\n";
//    cin >> x;
//
//    cout << "\n";
//    if(x == "y"){
//        cout << "------------- GAME ENGINE DRIVER CLASS ----------------\n";
//    CommandProcessorDriver cpd;
//    // file
//    if (argc > 1 && argv[1] == "-file")
//        cpd.callCommandProcessorDriver(true, argv[2]);
//        // console (default)
//    else
//        cpd.callCommandProcessorDriver(false, "");
//    }
//
//    cout << "\n";
//    cout << "Going to the next one please enter Y\n";
//    cin >> x;
//
//    cout << "\n";
//    if(x == "y"){
//        cout << "------------- MAP DRIVER CLASS ----------------\n";
//        MapDriver md;
//        md.callMapDriver();
//    }
//    cout << "\n";
//    cout << "Going to the next one please enter Y\n";
//    cin >> x;
//    cout << "\n";
//    if(x == "y"){
//        cout << "------------- PLAYER DRIVER CLASS ----------------\n";
//        PlayerDriver playerDriver;
//        playerDriver.callPlayerDriver();
//    }
//    cout << "Done";
    return 0;
}

