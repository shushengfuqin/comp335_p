//
// Created by admin on 2022/2/3.
//

#ifndef COMP335_P_ORDERS_H
#define COMP335_P_ORDERS_H

#include <iostream>
#include <list>
using namespace std;


struct Orders
{
    int id;
    string content;
    string name;
    Orders();
    Orders(int orderId,string orderName,string orderContent);
    ~Orders();

};

struct Bomb : public Orders {
public:
    int id;
    string content = "This is a Bomb Order";
    string name = "Bomb";

    Bomb( int orderId, string orderName, string orderContent);
    ~Bomb();
    string static BombName();
    static bool validate(int i);
    void execute(string i);
};


struct Deploy : public Orders{
public:
    int id;
    string content = "This is a Deploy Order";
    string name = "Deploy";
    Deploy( int orderId, string orderName, string orderContent) ;
    ~Deploy();
    string static DeployName();
    static bool validate(int i);
    void execute(string i);
};

struct Advance : public Orders{
public:
    int id;
    string content = "This is an Advance Order";
    string name = "Advance";
    Advance( int orderId, string orderName, string orderContent);
    ~Advance();
    string static AdvanceName();
    static bool validate(int i);
    void execute(string i);
};

struct Blockade : public Orders{
public:
    int id;
    string content = "This is a Blockade Order";
    string name = "Blockade";
    Blockade( int orderId, string orderName, string orderContent);
    ~Blockade();
    string static BlockadeName();
    static bool validate(int i);
    void execute(string i);
};

struct Airlift : public Orders{
public:
    int id;
    string content = "This is a Airlift Order";
    string name = "Airlift";
    Airlift( int orderId, string orderName, string orderContent) ;
    ~Airlift();
    string static AirliftName();
    static bool validate(int i);
    void execute(string i);
};

struct Negotiate : public Orders{
public:

    int id;
    string content = "This is a Negotiate Order";
    string name = "Negotiate";
    Negotiate( int orderId, string orderName, string orderContent) ;
    ~Negotiate();
    string static NegotiateName();
    static bool validate(int i);
    void execute(string i);
};







class Orderslist {




public:
    int length;
    Orderslist(int length);
    ~Orderslist();
    list<Orders> orderlist;
    void addOrder(Orders order);
    static bool remove(list<Orders> l, int position);
    void displayList();

/*    static void move();*/
};




#endif //COMP335_P_ORDERS_H
