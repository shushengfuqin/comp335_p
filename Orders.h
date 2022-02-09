//
// Created by admin on 2022/2/3.
//

#ifndef COMP335_P_ORDERS_H
#define COMP335_P_ORDERS_H

#include <string>
using namespace std;
class Orders {
public:


    static void initNode(struct Node *head, string n, bool isValidate, int orderID);
    static void addNode(struct Node *head, string n, bool isValidate, int orderID);
    static void insertFront(struct Node **head, string n,bool isValidate,int orderID);
    static bool deleteNode(struct Node **head, Node *ptrDel);
    static bool remove(struct Node **head, int targetPlace);
    static void deleteLinkedList(struct Node **node);
    static void display(struct Node *head);
    static Node* searchNode(struct Node *head, int n);
    static void move(struct Node **head, int index,int targetPlace );
};

struct Node {
    string orderName;
    bool isValidate;
    int orderID;
    Node *next;
};
#endif //COMP335_P_ORDERS_H
