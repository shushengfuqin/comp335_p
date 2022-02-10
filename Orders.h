//
// Created by admin on 2022/2/3.
//

#ifndef COMP335_P_ORDERS_H
#define COMP335_P_ORDERS_H

#include <string>
using namespace std;
class Orders {
public:

    Orders();
    ~Orders();
    static void initNode(struct Node *head, int typeNum, int orderID);
    static void addNode(struct Node *head, int typeNum, int orderId);
   /* static void insertFront(struct Node **head, string n,bool isValidate,int orderID);*/
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

class Bomb{
public:
    Bomb();
    ~Bomb();
    string static BombName();
    static bool validate(int i);
    void execute(string i);
};


class Deploy{
public:
    Deploy();
    ~Deploy();
    string static DeployName();
    static bool validate(int i);
    void execute(string i);
};

class Advance{
public:
    Advance();
    ~Advance();
    string static AdvanceName();
    static bool validate(int i);
    void execute(string i);
};

class Blockade{
public:
    Blockade();
    ~Blockade();
    string static BlockadeName();
    static bool validate(int i);
    void execute(string i);
};

class Airlift{
public:
    Airlift();
    ~Airlift();
    string static AirliftName();
    static bool validate(int i);
    void execute(string i);
};

class Negotiate{
public:
    Negotiate();
    ~Negotiate();
    string static NegotiateName();
    static bool validate(int i);
    void execute(string i);
};


#endif //COMP335_P_ORDERS_H
