//
// Created by admin on 2022/2/3.
//

#include "Orders.h"
#include <iostream>
#include <vector>




using namespace std;


//Order Class
Order::Order(){};
Order::Order(Player* player) {
    this->player = player;
}

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


bool Order::validate() {
    if (true) {
        valid = true;
        cout << "this order is valid and ready to be executed" << endl;

    }else {
        valid = false;
    }
    return valid;
}


void Order::execute() {
    if (validate()) {
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

const Player *Order::getOrderIssuer() {
    return player;
}

void Order::setOrderIssuer(Player *issuer) {
    player = issuer;
}


//Deploy class
Deploy::Deploy() : Order() {
    setID(0);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
};
Deploy::Deploy(Player *player,Territory* targetTerritory,unsigned int armies) : Order(player){
    this->player = player;
    this->targetTerritory = targetTerritory;
    this->armies = armies;

}

Deploy::~Deploy(){};

//copy constructor
Deploy::Deploy(const Deploy& copiedDe) {
    this->type = *new string (copiedDe.type);
    this->player = copiedDe.player;
    this->targetTerritory = copiedDe.targetTerritory;
    this->armies = copiedDe.armies;
}
//assignment operator
Deploy& Deploy::operator = (const Deploy&Deo){
    Order::operator=(Deo);
    player = Deo.player;
    targetTerritory = Deo.targetTerritory;
    armies = Deo.armies;
    return *this;
};

string* Deploy::getOrderType() {
    return &type;
}

bool Deploy::validate() {
    //Todo: targetTerritory.getPlayer() = getOrderIssuer()
    if(targetTerritory->getNumArmies()>0){
        cout<<"Deploy is valid and can be executed"<<endl;
        return true;
    }
    else {
        cout<<"Deploy is invalid"<<endl;
        return false;
    }
}

void Deploy::execute() {

    if(validate()){
        targetTerritory->setNumArmies(targetTerritory->getNumArmies()+armies);
        cout<<armies<<"armies has been deployed to the territory"<<targetTerritory<<endl;
    } else{
        cout<<"deploy cannot be executed"<<endl;
    }
}




//Advance class
Advance::Advance() :Order() {
    setID(1);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Advance::Advance(Player* player, Territory* fromTerritory,Territory* toTerritory,unsigned int armies) : Order(player){
    this->fromTerritory = fromTerritory;
    this->toTerritory = toTerritory;
    this->armies = armies;

}
//copy constructor
Advance::Advance(const Advance& copiedAd) {
    this->type = *new string (copiedAd.type);
    this->fromTerritory = copiedAd.fromTerritory;
    this->toTerritory= copiedAd.toTerritory;
    this->armies = copiedAd.armies;

}
Advance::~Advance() {
    delete this->fromTerritory;
    delete this->toTerritory;
    delete this;
};


//assignment operator
Advance& Advance::operator = (const Advance&Ao){
    Order::operator=(Ao);
    player = Ao.player;
    fromTerritory = Ao.fromTerritory;
    toTerritory = Ao.toTerritory;
    armies = Ao.armies;
    return *this;
};

string* Advance::getOrderType() {
    return &type;
}

bool Advance::validate() {
    //Todo: fromTerritories. getPlayer = getOrderIssuer(), two territories are adjacent
    if (fromTerritory->getNumArmies()>3) //just put it here
        return true;
    return false;
}
void Advance::execute() {
    if(validate()){
        //Todo: fromTerritories.getPlayer = toTerritories.getPlayer
        if(fromTerritory->getNumArmies()>0)//Todo:this need to be fixed
            {
            fromTerritory->setNumArmies(fromTerritory->getNumArmies()-armies);
            toTerritory->setNumArmies(toTerritory->getNumArmies()+armies);
            cout<<"Advance"<<armies<<"armies from "<<fromTerritory->getName()<<"to "<<toTerritory->getName()<<endl;
        }
        else{
            while(toTerritory->getNumArmies()>0 || fromTerritory->getNumArmies()>0){
                srand(time(NULL));
                if(rand() % 10 < 6)
                    toTerritory->setNumArmies(toTerritory->getNumArmies()-1);
                else if(rand() % 10 < 7)
                    fromTerritory->setNumArmies(fromTerritory->getNumArmies()-1);
                    armies--;
            }
            if(toTerritory->getNumArmies()==0){
                //Todo: toTerritory.setPlayer(fromTerritory.getPlayer)
                toTerritory->setNumArmies(toTerritory->getNumArmies()+armies);
                //Todo:A player receives a card
            }
        }
    }
    else
        cout<<" advance cannot be executed"<<endl;
}


// Bomb class

Bomb::Bomb() :Order(){
    setID(2);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}

Bomb::Bomb(Player* player,Territory* targetTerritory) :Order(player){
    this->player = player;
    this->targetTerritory = targetTerritory;

}


//copy constructor
Bomb::Bomb(const Bomb& copiedBo) {
    this->type = *new string (copiedBo.type);
    this->targetTerritory = copiedBo.targetTerritory;
    this->player = copiedBo.player;
}


Bomb::~Bomb(){
    delete this->targetTerritory;
    delete this;
};

//assignment operator
Bomb& Bomb::operator = (const Bomb&Bo){
    Order::operator=(Bo);
    player = Bo.player;
    targetTerritory = Bo.targetTerritory;
    return *this;
};

string* Bomb::getOrderType() {
    return &type;
}

bool Bomb::validate() {


}
void Bomb::execute() {}

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
Airlift::Airlift() :Order(){
    setID(4);
    cout<<"The order"<<" "<<type<<" is been placed"<<endl;
}
Airlift::Airlift(Player* player,Territory* fromTerritory,Territory* toTerritory,unsigned int armies) : Order(player){
    this->fromTerritory = fromTerritory;
    this->toTerritory = toTerritory;
    this->armies = armies;
}

//copy constructor
Airlift::Airlift(const Airlift& copiedAir){
    this->type = *new string (copiedAir.type);
    this->fromTerritory = copiedAir.fromTerritory;
    this->toTerritory = copiedAir.toTerritory;
}

Airlift::~Airlift() {
    delete this->fromTerritory;
    delete this->toTerritory;
    delete this;
};


//assignment operator
Airlift& Airlift::operator = (const Airlift&Airo){
    Order::operator=(Airo);
    fromTerritory = Airo.fromTerritory;
    toTerritory = Airo.toTerritory;
    return *this;
};

string* Airlift::getOrderType() {
    return &type;
}

bool Airlift::validate() {
    //Todo: fromTerritory.getPlayer == getOrderIssuer() && toTerritory.getPlayer == getOrderIssuer()
    return true;
    //else  return false
}

void Airlift::execute() {
        //Todo::if the playing the airlift card
        if(validate()){
            fromTerritory->setNumArmies(fromTerritory->getNumArmies()-armies);
            toTerritory->setNumArmies(toTerritory->getNumArmies()+armies);
        }
        else
            cout<<"No airlift card is creating or airlift order is invalid"<<endl;
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

Orderslist::Orderslist()= default;;
Orderslist::~Orderslist()= default;;

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


