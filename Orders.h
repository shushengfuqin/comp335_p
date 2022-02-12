//
// Created by admin on 2022/2/3.
//

#ifndef COMP335_P_ORDERS_H
#define COMP335_P_ORDERS_H

#include <iostream>
#include <vector>
using namespace std;


struct Order
{
public:
    //constructor & destructor
    Order();
    ~Order();

    void validate();
    void excute();


    void setID(int i);
    string getOrderType();

private:
    int id;
    bool valid;
    vector<string> orders = {"deploy","advance","bomb","blockade","airlift","negotiate"};
};

struct Bomb : public Order {
public:


    Bomb();
    ~Bomb();
    string* getOrderType();

private:
    string type = {"bomb"};
};


struct Deploy : public Order{
public:

    Deploy() ;
    ~Deploy();
    string* getOrderType();

private:
    string type = {"deploy"};
};

struct Advance : public Order{
public:

    Advance();
    ~Advance();
    string* getOrderType();

private:
    string type = {"advance"};
};

struct Blockade : public Order{
public:

    Blockade();
    ~Blockade();
    string* getOrderType();

private:
    string type = {"blockade"};
};

struct Airlift : public Order{
public:

    Airlift() ;
    ~Airlift();
    string* getOrderType();

private:
    string type = {"airlift"};
};

struct Negotiate : public Order{
public:


    Negotiate() ;
    ~Negotiate();
    string* getOrderType();

private:
    string type = {"negotiate"};
};







class Orderslist {


public:

    Orderslist();
    ~Orderslist();

    //getter setter of the orderlist
    void setOrderList(Order* order);
    vector<Order*>* getOrderList();

    //methods to modify the list
    void remove(Order* order);
    void move(int origin,int targetPosition);

private:
    vector<Order*> orderlist;
};




#endif //COMP335_P_ORDERS_H
