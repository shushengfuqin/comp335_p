//
// Created by admin on 2022/2/3.
//

#include "OrdersList.h"
#include <iostream>

using namespace std;

struct Node {
    string orderName;
    bool isValidate;
    int orderID;
    Node *next;
};

void initNode(struct Node *head, string n, bool isValidate, int orderID) {
    head->orderName = n;
    head->isValidate = isValidate;
    head->orderID = orderID;
    head->next = NULL;
}

void addNode(struct Node *head, string n, bool isValidate, int orderID) {
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


    void insertFront(struct Node **head, string n,bool isValidate,int orderID) {
        Node *newNode = new Node;
        newNode->orderName = n;
        newNode->isValidate = isValidate;
        newNode->orderID = orderID ;
        newNode->next = *head;
        *head = newNode;
    }


/*
      struct Node *searchNode(struct Node *head, string n) {
        Node *cur = head;
        while(cur) {
            if(cur->orderName == n ) return cur;
            cur = cur->next;
        }
        cout << "Cannot Find Order " << n << " in list.\n";
    }
*/






bool deleteNode(struct Node **head, Node *ptrDel) {
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

bool remove(struct Node **head, int orderID) {
    int index = 0;
    Node *cur = *head;


    while (cur) {

        if (orderID == index) {
            return deleteNode(head, cur);
        }
        cur = cur->next;
    }
    return false;

}


void deleteLinkedList(struct Node **node) {
    struct Node *tmpNode;
    while (*node) {
        tmpNode = *node;
        *node = tmpNode->next;
        delete tmpNode;
    }
}

void display(struct Node *head) {
    Node *list = head;
    while (list) {
        cout << list->orderName << " ";
        list = list->next;
    }
    cout << endl;
    cout << endl;
}

void move(struct Node **head, Node *n1,int targetPlace ) {
    int index=0;
    Node *cur=*head;
    if(n1==*head){
        n1=n1->next;
        return;
    }
    while(cur){
        if(cur->next==n1){
            cur->next=cur->next->next;
            break;
        }
        cur=cur->next;
    }

    cur=*head;
    if(targetPlace==0){
        n1->next=*head;
        return;
    }
    while(index==targetPlace-1){

        index++;
        cur=cur->next;
    }
    Node* temp=cur->next;
    cur->next=n1;
    n1->next=temp;



}


