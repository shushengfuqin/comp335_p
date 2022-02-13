#include <iostream>
#include "./src/Cards/CardsDriver.cpp"
#include "OrdersDriver.cpp"

int main() {

    cout << "------------- ORDER DRIVER CLASS ----------------\n";
    OrdersDriver od;
    od.callOrdersDriver();

    cout << "------------- CARDS DRIVER CLASS ----------------\n";
    CardDriver cd;
    cd.callCardDriver();
    return 0;
}
