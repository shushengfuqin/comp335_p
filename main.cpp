
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
    string x;

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
    cout << "Going to the next one please enter Y\n";
    cin >> x;
    cout << "\n";
    if(x == "y"){
        cout << "------------- PLAYER DRIVER CLASS ----------------\n";
        PlayerDriver playerDriver;
        playerDriver.callPlayerDriver();
    }
    cout << "Done";
    return 0;
}

