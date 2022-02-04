//
// Created by admin on 2022/2/3.
//

#include "OrdersList.h"
#include <iostream>

using namespace std;

struct Node {
    string orderName;
    Node* next;
};

// only for the 1st Node
void initNode(struct Node *head,string n){
    head->orderName = n;
    head->next =NULL;
}

// apending
void addNode(struct Node *head, string n) {
    Node *newNode = new Node;
    newNode->orderName = n;
    newNode->next = NULL;

    Node *cur = head;
    while(cur) {
        if(cur->next == NULL) {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}

void insertFront(struct Node **head, string n) {
    Node *newNode = new Node;
    newNode->orderName = n;
    newNode->next = *head;
    *head = newNode;
}

struct Node *searchNode(struct Node *head, string n) {
    Node *cur = head;
    while(cur) {
        if(cur->orderName == n) return cur;
        cur = cur->next;
    }
    cout << "Cannot Find Order " << n << " in list.\n";
}

bool deleteNode(struct Node **head, Node *ptrDel) {
    Node *cur = *head;
    if(ptrDel == *head) {
        *head = cur->next;
        delete ptrDel;
        return true;
    }

    while(cur) {
        if(cur->next == ptrDel) {
            cur->next = ptrDel->next;
            delete ptrDel;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

/* reverse the list */
struct Node* reverse(struct Node** head)
{
    Node *parent = *head;
    Node *me = parent->next;
    Node *child = me->next;

    /* make parent as tail */
    parent->next = NULL;
    while(child) {
        me->next = parent;
        parent = me;
        me = child;
        child = child->next;
    }
    me->next = parent;
    *head = me;
    return *head;
}

/* Creating a copy of a linked list */
void copyLinkedList(struct Node *node, struct Node **pNew)
{
    if(node != NULL) {
        *pNew = new Node;
        (*pNew)->orderName = node->orderName;
        (*pNew)->next = NULL;
        copyLinkedList(node->next, &((*pNew)->next));
    }
}



void deleteLinkedList(struct Node **node)
{
    struct Node *tmpNode;
    while(*node) {
        tmpNode = *node;
        *node = tmpNode->next;
        delete tmpNode;
    }
}

void display(struct Node *head) {
    Node *list = head;
    while(list) {
        cout << list->orderName << " ";
        list = list->next;
    }
    cout << endl;
    cout << endl;
}

