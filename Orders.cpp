//
// Created by admin on 2022/2/3.
//

#include "Orders.h"
#include <iostream>

using namespace std;




void Orders::initNode(struct Node *head, string n, bool isValidate, int orderID) {
    head->orderName = n;
    head->isValidate = isValidate;
    head->orderID = orderID;
    head->next = NULL;

}

void Orders::addNode(struct Node *head, string n, bool isValidate, int orderID) {
    Node *newNode = new Node;
    newNode->orderName = n;
    newNode->isValidate = isValidate;
    newNode->orderID = orderID;
    newNode->next = NULL;


    Node *cur = head;
    while (cur) {
        if (cur->next == NULL) {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}


void Orders::insertFront(struct Node **head, string n, bool isValidate, int orderID) {
    Node *newNode = new Node;
    newNode->orderName = n;
    newNode->isValidate = isValidate;
    newNode->orderID = orderID;
    newNode->next = *head;
    *head = newNode;

}


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





