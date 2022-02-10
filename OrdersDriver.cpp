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


    Orders::initNode(order, 0,3);
    Orders::display(order);
    //Add 5 more orders into the list following the first order
    Orders::addNode(order, 1,  9);
    Orders::display(order);

    Orders::addNode(order, 2, 5);
    Orders::display(order);

    Orders::addNode(order, 3, 0);
    Orders::display(order);

    Orders::addNode(order, 4,  8);
    Orders::display(order);

    Orders::addNode(order, 5,  7);
    Orders::display(order);




/*    Orders::remove(&order,2);
    Orders::display(order);*/
/*

    Node *ptrNode = Orders::searchNode(order, 5);
    Orders::display(ptrNode);
*/

    Orders::move(&thisHead, 0, 2);
    Orders::display(thisHead);
}