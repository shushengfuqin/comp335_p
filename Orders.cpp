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


string* Deploy::getOrderType() {
    return &type;
}

//Advance class
Advance::Advance() {
    setID(1);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Advance::~Advance() {};


string* Advance::getOrderType() {
    return &type;
}


// Bomb class

Bomb::Bomb(){
    setID(2);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Bomb::~Bomb(){};


string* Bomb::getOrderType() {
    return &type;
}

//Blockade class
Blockade::Blockade() {
    setID(3);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Blockade::~Blockade() {};


string* Blockade::getOrderType() {
    return &type;
}

//Airlift class
Airlift::Airlift() {
    setID(4);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Airlift::~Airlift() {};


string* Airlift::getOrderType() {
    return &type;
}

//Negotiate class
Negotiate::Negotiate() {
    setID(5);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Negotiate::~Negotiate() {};


string* Negotiate::getOrderType() {
    return &type;
}



//implementation of Orderslist


Orderslist::Orderslist(){};
Orderslist::~Orderslist(){};

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

