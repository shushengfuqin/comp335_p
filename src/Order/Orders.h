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
    Order(const Order& copiedO);
    Order& operator = (const Order &O);
    friend ostream & operator <<(ostream &out, const Order &o);
    friend istream & operator >> (istream &in,  Order &o);
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
    Bomb(const Bomb& copiedBo);
    Bomb& operator = (const Bomb &Bo);
    string* getOrderType();

private:
    string type = {"bomb"};
};


struct Deploy : public Order{
public:

    Deploy() ;
    ~Deploy();
    Deploy(const Deploy& copiedDe);
    Deploy& operator = (const Deploy &Do);
    string* getOrderType();

private:
    string type = {"deploy"};
};

struct Advance : public Order{
public:

    Advance();
    ~Advance();
    Advance(const Advance& copiedAd);
    Advance& operator = (const Advance &Ao);
    string* getOrderType();

private:
    string type = {"advance"};
};

struct Blockade : public Order{
public:

    Blockade();
    ~Blockade();
    Blockade(const Blockade& copiedBl);
    Blockade& operator = (const Blockade &Blo);
    string* getOrderType();

private:
    string type = {"blockade"};
};

struct Airlift : public Order{
public:

    Airlift() ;
    ~Airlift();
    Airlift(const Airlift& copoedAir);
    Airlift& operator = (const Airlift &Airo);
    string* getOrderType();

private:
    string type = {"airlift"};
};

struct Negotiate : public Order{
public:


    Negotiate() ;
    ~Negotiate();
    Negotiate(const Negotiate& copiedNe);
    Negotiate& operator = (const Negotiate &Neo);
    string* getOrderType();

private:
    string type = {"negotiate"};
};







class Orderslist {


public:

    Orderslist();
    ~Orderslist();
    Orderslist(const Orderslist& copiedOl);
    Orderslist& operator = (const Orderslist &Ol);
    friend ostream & operator <<(ostream &out, const Orderslist &ol);
    friend istream & operator >> (istream &in,  Orderslist &ol);
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