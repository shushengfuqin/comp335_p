//
// Created by admin on 2022/2/6.
//

#include <iostream>
#include "Orders.h"

using namespace std;

int main() {


    Bomb bomb1(1,"bomb","bomb1");
    Deploy deploy1(2,"deploy","deploy1");
    Advance advance1(3,"advance","advance1");
    Blockade blockade1(4,"blockade","blockade1");
    Airlift airlift1(5,"airlift","airlift1");
    Negotiate negotiate1(6,"negotiate","negotiate1");


    Orderslist ol1 = Orderslist(8);
    ol1.addOrder(bomb1);
    ol1.displayList();


}