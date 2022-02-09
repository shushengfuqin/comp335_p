//
// Created by admin on 2022/2/6.
//

#include <iostream>
#include "OrdersList.h"

using namespace std;

int main() {
    OrdersList ordersList;
    struct Node *order = new Node;
    struct Node *thisHead = order;

    OrdersList::initNode(order,"Bomb",true,1);
    OrdersList::display(order);

    OrdersList::addNode(order,"Deploy",true,2);
    OrdersList::display(order);

    OrdersList::addNode(order,"Advance",true,3);
    OrdersList::display(order);

    OrdersList::addNode(order,"blockade",true,4);
    OrdersList::display(order);
/*
    struct Node *cur = order;
    for(int i = 0; i < 4; i++){
        cur = cur->next;
    }
    OrdersList::move(&thisHead,cur,1);
    OrdersList::display(order);

*/
/*

    OrdersList::remove(&order,1);
    OrdersList::display(order);*/

    //这个可以用
    Node *ptrNode = OrdersList::searchNode(order,4);
    OrdersList::display(ptrNode);

    //Node *ptargetNode = OrdersList::findPreTargetNode(order,3);
    //OrdersList::display(ptargetNode);

    OrdersList::move(&thisHead,2,2);
    OrdersList::display(thisHead);
}