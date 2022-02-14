#include <iostream>
#include <string>
#include "./src/Cards/CardsDriver.cpp"
#include "OrdersDriver.cpp"
#include "GameEngineDriver.cpp"

using namespace std;

int main() {
    string x;

    cout << "------------- ORDER DRIVER CLASS ----------------\n";
    OrdersDriver od;
    od.callOrdersDriver();

    cout << "Going to the next one please enter Y\n";
    cin >> x;
    cout << "\n";
    if(x == "y"){
        cout << "------------- CARDS DRIVER CLASS ----------------\n";
        CardsDriver cd;
        cd.callCardsDriver();
    }

    cout << "Going to the next one please enter Y\n";
    cin >> x;
    cout << "\n";
    if(x == "y"){
        cout << "------------- GAME Engine DRIVER CLASS ----------------\n";
        GameEngineDriver::callGameEngineDriver();
    }
    return 0;
}
