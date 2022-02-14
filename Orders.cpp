//
// Created by admin on 2022/2/3.
//

#include "Orders.h"
#include <iostream>
#include <vector>

using namespace std;

//Order Class
Order::Order() {};
Order::~Order() {};

//copy constructor
Order::Order(const Order& copiedO) {
    this->orders = *new vector<string>(copiedO.orders);
    this->id = *new int(copiedO.id);
    this->valid = *new bool (copiedO.valid);
}
//assignment operator
Order& Order::operator = (const Order&O){
    return *this;
};

//stream insert operator
ostream & operator << (ostream &out, const Order &o)
{
    out <<"id: "<< o.id;
    out <<"validation: "<< o.valid<< endl;
    return out;
}

istream & operator >> (istream &in,  Order &o)
{
    cout << "Enter id ";
    in >> o.id;
    cout << "Enter Imaginary Part ";
    in >> o.valid;
    return in;
}


void Order::validate() {
    if (true) {
        valid = true;
        cout << "this order is valid and ready to be executed" << endl;

    }else {
        valid = false;
    }
}


void Order::excute() {
    if (valid) {
        cout << "the order has been executed" << endl;
    }else{
        cout <<"the order is invalid and cannot be executed" <<endl;
    }
}

void Order::setID(int i) {
    id = i;
}

string Order::getOrderType() {
    return orders.at(id);
}



//Deploy class
Deploy::Deploy() {
    setID(0);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Deploy::~Deploy(){};

//copy constructor
Deploy::Deploy(const Deploy& copiedDe) {
    this->type = *new string (copiedDe.type);
}
//assignment operator
Deploy& Deploy::operator = (const Deploy&Deo){
    return *this;
};

string* Deploy::getOrderType() {
    return &type;
}

//Advance class
Advance::Advance() {
    setID(1);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Advance::~Advance() {};


//copy constructor
Advance::Advance(const Advance& copiedAd) {
    this->type = *new string (copiedAd.type);
}
//assignment operator
Advance& Advance::operator = (const Advance&Ao){
    return *this;
};

string* Advance::getOrderType() {
    return &type;
}


// Bomb class

Bomb::Bomb(){
    setID(2);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Bomb::~Bomb(){};

//copy constructor
Bomb::Bomb(const Bomb& copiedBo) {
    this->type = *new string (copiedBo.type);
}
//assignment operator
Bomb& Bomb::operator = (const Bomb&Bo){
    return *this;
};

string* Bomb::getOrderType() {
    return &type;
}

//Blockade class
Blockade::Blockade() {
    setID(3);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Blockade::~Blockade() {};

//copy constructor
Blockade::Blockade(const Blockade& copiedBl) {
    this->type = *new string (copiedBl.type);
}
//assignment operator
Blockade& Blockade::operator = (const Blockade&Blo){
    return *this;
};

string* Blockade::getOrderType() {
    return &type;
}

//Airlift class
Airlift::Airlift() {
    setID(4);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Airlift::~Airlift() {};

//copy constructor
Airlift::Airlift(const Airlift& copiedAir){
    this->type = *new string (copiedAir.type);
}
//assignment operator
Airlift& Airlift::operator = (const Airlift&Airo){
    return *this;
};

string* Airlift::getOrderType() {
    return &type;
}

//Negotiate class
Negotiate::Negotiate() {
    setID(5);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Negotiate::~Negotiate() {};

//copy constructor
Negotiate::Negotiate(const Negotiate& copiedNe){
    this->type = *new string (copiedNe.type);
}
//assignment operator
Negotiate& Negotiate::operator = (const Negotiate&Neo){
    return *this;
};

string* Negotiate::getOrderType() {
    return &type;
}



//implementation of Orderslist

Orderslist::Orderslist(){};
Orderslist::~Orderslist(){};

//copy constructor
Orderslist::Orderslist(const Orderslist& copiedOl) {
    this->orderlist = *new vector<Order*>(copiedOl.orderlist);
}

//assignment operator
Orderslist& Orderslist::operator = (const Orderslist&Ol){
    return *this;
};


//stream insert operator
 ostream & operator << (ostream &out, const Orderslist &o)
{
    return out;
}

istream & operator >> (istream &in,  Orderslist &o)
{
    return in;
}

//add order
void Orderslist::setOrderList(Order *order) {
    orderlist.push_back(order);
}
//get the orderlist
vector<Order*>* Orderslist::getOrderList() {
    return &orderlist;
}

//remove given element from the orderlist
void Orderslist::remove(Order* order) {
    for (int i = 0; i < orderlist.size(); i++) {
        if (order->getOrderType() == orderlist.at(i)->getOrderType()) {
            orderlist.erase(orderlist.begin() + i);
            cout << "The order" << order->getOrderType() << "has been removed from the list" << endl;
            return;
        }
    }
}




void Orderslist::move(int origin, int targetPosition)
{
    //origin and targetPosition are in list
    if (origin >= 0 && origin < orderlist.size() && targetPosition >= 0 && targetPosition <orderlist.size())
    {
        //insert the order from origin to targetPosition before erase
        orderlist.insert(orderlist.begin() + targetPosition, orderlist.at(origin));
        orderlist.erase(orderlist.begin() + origin);
    }
    else if (targetPosition == orderlist.size()  )//targetPosition at the end of the list
    {
        orderlist.push_back(orderlist.at(origin));
        orderlist.erase(orderlist.begin() + origin);
    }
    else {
        cout << "\n the element cannot be move to the target position" << endl;
    }
}


