//
// Created by admin on 2022/2/6.
//

#include <iostream>
#include "Orders.h"

using namespace std;

int main() {

    struct Node *order = new Node;
    struct Node *thisHead = order;

    //First initiate the first order of the orderlist
    Orders::initNode(order, 1, true, 3);
    Orders::display(order);
    //Add 5 more orders into the list following the first order
//    Orders::addNode(order, "Deploy", true, 5);
//    Orders::display(order);
//
//    Orders::addNode(order, "Advance", true, 0);
//    Orders::display(order);
//
//    Orders::addNode(order, "Blockade", true, 2);
//    Orders::display(order);
//
//    Orders::addNode(order, "Airlift", true, 9);
//    Orders::display(order);
//
//    Orders::addNode(order, "Negotiate", true, 6);
//    Orders::display(order);

/*

    Orders::remove(&order,2);
    Orders::display(order);
*/


/*    Node *ptrNode = Orders::searchNode(order, 6);
    Orders::display(ptrNode);*/

    Orders::move(&thisHead, 2, 2);
    Orders::display(thisHead);
}