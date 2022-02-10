//
// Created by admin on 2022/2/3.
//

#include "Orders.h"
#include <iostream>

using namespace std;




void Orders::initNode(struct Node *head, int typeNum, int orderId) {
    switch(typeNum){
        // 0 means the order is bomb
        case 0:
            head->orderName = Bomb::BombName();
            head->isValidate = Bomb::validate(1);
            head->orderID = orderId;
            head->next = NULL;

            break;
        case 1: // 1 means the order is deploy
            head->orderName = Deploy::DeployName();
            head->isValidate = Deploy::validate(1);
            head->orderID = orderId;
            head->next = NULL;
            break;
        case 2: // 2 means the order is Advance
            head->orderName = Advance::AdvanceName();
            head->isValidate = Advance::validate(1);
            head->orderID = orderId;
            head->next = NULL;
            break;
        case 3: // 3 means the order is Blockade
            head->orderName = Blockade::BlockadeName();
            head->isValidate = Blockade::validate(1);
            head->orderID = orderId;
            head->next = NULL;
            break;
        case 4: // 4 means the order is Airlift
            head->orderName = Airlift::AirliftName();
            head->isValidate = Airlift::validate(1);
            head->orderID = orderId;
            head->next = NULL;
            break;
        case 5: // 5 means the order is Negotiate
            head->orderName = Negotiate::NegotiateName();
            head->isValidate = Negotiate::validate(1);
            head->orderID = orderId;
            head->next = NULL;
            break;
        default:
            cout << "Invalid Order\n";
    }
/*    head->orderName = n;
    head->isValidate = isValidate;
    head->orderID = orderID;*/


}

void Orders::addNode(struct Node *head, int typeNum,int orderId) {
    Node *newNode = new Node;
    switch(typeNum){
        // 0 means the order is bomb
        case 0:
            newNode->orderName = Bomb::BombName();
            newNode->isValidate = Bomb::validate(1);
            newNode->orderID = orderId;
            newNode->next = NULL;
            break;
        case 1: // 1 means the order is deploy
            newNode->orderName = Deploy::DeployName();
            newNode->isValidate = Deploy::validate(1);
            newNode->orderID = orderId;
            newNode->next = NULL;
            break;
        case 2: // 2 means the order is Advance
            newNode->orderName = Advance::AdvanceName();
            newNode->isValidate = Advance::validate(1);
            newNode->orderID = orderId;
            newNode->next = NULL;
            break;
        case 3: // 3 means the order is Blockade
            newNode->orderName = Blockade::BlockadeName();
            newNode->isValidate = Blockade::validate(1);
            newNode->orderID = orderId;
            newNode->next = NULL;
            break;
        case 4: // 4 means the order is Airlift
            newNode->orderName = Airlift::AirliftName();
            newNode->isValidate = Airlift::validate(1);
            newNode->orderID = orderId;
            newNode->next = NULL;
            break;
        case 5: // 5 means the order is Negotiate
            newNode->orderName = Negotiate::NegotiateName();
            newNode->isValidate = Negotiate::validate(1);
            newNode->orderID = orderId;
            newNode->next = NULL;
            break;
        default:
            cout << "Invalid Order\n";
    }
/*
    newNode->orderName = n;
    newNode->isValidate = isValidate;
    newNode->orderID = orderID;
    newNode->next = NULL;
*/


    Node *cur = head;
    while (cur) {
        if (cur->next == NULL) {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}

/*

void Orders::insertFront(struct Node **head, string n, bool isValidate, int orderID) {
    Node *newNode = new Node;
    newNode->orderName = n;
    newNode->isValidate = isValidate;
    newNode->orderID = orderID;
    newNode->next = *head;
    *head = newNode;

}

*/

struct Node *Orders::searchNode(struct Node *head, int n) {
    Node *cur = head;
    while (cur) {
        if (cur->orderID == n) return cur;
        cur = cur->next;
    }
    cout << "Cannot Find Order " << n << " in list.\n";
}


bool Orders::deleteNode(struct Node **head, Node *ptrDel) {
    Node *cur = *head;
    if (ptrDel == *head) {
        *head = cur->next;
        delete ptrDel;
        return true;
    }

    while (cur) {
        if (cur->next == ptrDel) {
            cur->next = ptrDel->next;
            delete ptrDel;
            return true;
        }
        cur = cur->next;
    }
    return false;
}


void Orders::deleteLinkedList(struct Node **node) {
    struct Node *tmpNode;
    while (*node) {
        tmpNode = *node;
        *node = tmpNode->next;
        delete tmpNode;
    }
}

void Orders::display(struct Node *head) {
    Node *list = head;
    while (list) {
        cout << list->orderName << " ";
    /*    cout << list->isValidate << " ";*/
        cout << list->orderID << " ";
        list = list->next;
    }
    cout << endl;
    cout << endl;
}



/*
    void Orders::move(struct Node **head, int index,int targetPlace ) {
        Node *cur = *head;
        Node *n1 = searchNode(*head, index);
        Node *preTarget = findPreTargetNode(*head, targetPlace);
        Node *temp;

        if (n1 == *head) {
            n1 = n1->next;
            return;
        }
        while (cur) {
            if (cur->next = n1) {
                temp = n1;
                cur->next = n1->next;
                temp->next = preTarget->next->next;
                preTarget->next = temp;
            }
            cur = cur->next;
        }

    }*/




// methods that required for the assignment 1

//remove method allows removing order from the list
bool Orders::remove(struct Node **head, int targetPlace) {
    int index = 0;
    Node *cur = *head;


    while (cur) {

        if (targetPlace == index) {
            return deleteNode(head, cur);
        }
        cur = cur->next;
        index++;
    }
    return false;

}

//move method can move the order with specific id to the target place
void Orders::move(Node **head, int index, int targetPlace) {
    Node *cur = *head;
    Node *n1 = searchNode(*head, index);


    if (n1 == *head) {
        *head = cur->next;

    } else {
        while (cur != n1) {

            if (cur->next == n1) {

                cur->next = cur->next->next;
                break;
            }
            cur = cur->next;
        }

    }
 /*   display(*head);*/
    if (targetPlace == 0) {
        n1->next = *head;
        *head = n1;
    } else {
        Node *cur1 = *head;
        for (int i = 0; i < targetPlace - 1; i++) {
            cur1 = cur1->next;

        }
        if (cur1->next) {

            Node *temp = cur1->next;
            cur1->next = n1;
            n1->next = temp;
        } else {
            cur1->next = n1;
            n1->next = NULL;
        }

    }
 /*   display(*head);*/


}

//validate if the order can be executed

// Bomb class

string Bomb::BombName(){
    return "Bomb";
}
bool Bomb::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Bomb::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}


// deploy class

string Deploy::DeployName(){
    return "Deploy";
}
bool Deploy::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Deploy::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}

//Advance class
string Advance::AdvanceName()  {
    return "Advance";
}
bool Advance::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Advance::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}

//Blockade class
string Blockade::BlockadeName(){
    return "Blockade";
}
bool Blockade::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Blockade::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}

//Airlift class
string Airlift::AirliftName() {
    return "Airlift";
}
bool Airlift::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Airlift::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}

//Negotiate class
string Negotiate::NegotiateName() {
    return "Negotiate";
}
bool Negotiate::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Negotiate::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}