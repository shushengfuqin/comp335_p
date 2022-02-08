//
// Created by admin on 2022/2/3.
//

#ifndef COMP335_P_ORDERSLIST_H
#define COMP335_P_ORDERSLIST_H

#include <string>
using namespace std;
class OrdersList {
public:


    static void initNode(struct Node *head, string n, bool isValidate, int orderID);
    static void addNode(struct Node *head, string n, bool isValidate, int orderID);
    static void insertFront(struct Node **head, string n,bool isValidate,int orderID);
    static bool deleteNode(struct Node **head, Node *ptrDel);
    static bool remove(struct Node **head, int orderID);
    static void deleteLinkedList(struct Node **node);
    static void display(struct Node *head);
    static void move(struct Node **head, int index,int targetPlace );
    static Node* searchNode(struct Node *head, int n);
    static struct Node* findPreTargetNode(struct Node *head,int n);
};

struct Node {
    string orderName;
    bool isValidate;
    int orderID;
    Node *next;
};
#endif //COMP335_P_ORDERSLIST_H
