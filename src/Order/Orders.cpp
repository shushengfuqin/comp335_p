//
// Created by yuxin wang on 2022/2/3.
//

#include "Orders.h"
#include <iostream>
#include <vector>


using namespace std;



/*********** ORDER ************/
//Order Class
// Here are the 1. default constructor
// 2. constructor with the order issuer (player)

Order::Order(){};
Order::Order(Player* player) {
    this->player = player;
}

//destructor for order
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

//validate method to validate if the order can be executed
bool Order::validate() {
        if(valid){
            cout << "this order is valid and ready to be executed\n" << endl;
            return true;
        } else
            return false;
}

//if the order is valid, then it can be executed
//for each specific order, it will have different executions
void Order::execute() {
    if (validate()) {
        cout << "the order has been executed\n" << endl;
    }else{
        cout <<"the order is invalid and cannot be executed\n" <<endl;
    }
}

//set id for this order
void Order::setID(int i) {
    id = i;
}

//get the type of this order by its id
string Order::getOrderType() {
    return orders.at(id);

}

/*
// To get who is the player issues the order
const Player *Order::getOrderIssuer() {
    return player;
}
*/

// TO set who is the player issues the order
void Order::setOrderIssuer(Player *issuer) {
    player = issuer;
}





/*********** DEPLOY ************/
//Deploy class
//Deploy order constructor without signed player
Deploy::Deploy() : Order() {
    setID(0);
    cout<<"The order"<<" "<<getOrderType()<<" is been placed\n"<<endl;
};
//Deploy order with
Deploy::Deploy(Player *player,Territory* targetTerritory,unsigned int armies) : Order(player){
    setID(0);
    this->player = player;
    this->targetTerritory = targetTerritory;
    this->armies = armies;
    cout<<"The order"<<" "<<getOrderType()<<" is been placed"<<" with issuer "<<player->getPlayerId()<<" with target territory "<<targetTerritory->getName()<<" with number of armies "<<armies<<"\n"<<endl;

}

Deploy::~Deploy(){};

//copy constructor
Deploy::Deploy(const Deploy& copiedDe) {
/*    this->type = *new string (copiedDe.type);*/
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


//If the target territory does not belong to the player that issued the order, the order is invalid.
bool Deploy::validate() {

    if( player->containsTerritory(targetTerritory)){
        cout<<"Deploy is valid and can be executed\n"<<endl;
        return true;
    }
    else {
        cout<<"Deploy is invalid\n"<<endl;
        return false;
    }
}


//If the target territory belongs to the player that issued the deploy order,
// the selected number of armies is added to the number of armies on that territory.
void Deploy::execute() {

    if(validate()){
//        player->removeArmyNum(armies);
        targetTerritory->setNumArmies(targetTerritory->getNumArmies()+armies);
        cout<<armies<<" armies has been deployed to the territory "<<targetTerritory->getName()<<"\n"<<endl;
    } else{
        cout<<"deploy cannot be executed\n"<<endl;
    }
    Notify(this);
}

string Deploy::stringToLog() {
    return "Deploy executed";
}




/*********** ADVANCE ************/
//Advance class
Advance::Advance() :Order() {
    setID(1);
    cout<<"The order"<<" "<<getOrderType()<<" is been placed\n"<<endl;
}

Advance::Advance(Player* player, Territory* fromTerritory,Territory* toTerritory,unsigned int armies) : Order(player){
    setID(1);
    this->fromTerritory = fromTerritory;
    this->toTerritory = toTerritory;
    this->armies = armies;
    cout<<"The order advance is been placed with issuer "<<player->getPlayerId()<<" from Territory "<<fromTerritory->getName()<<" to Territory "<<toTerritory->getName()<<"with number of armies "<<armies<<"\n"<<endl;
}
//copy constructor
Advance::Advance(const Advance& copiedAd) {
 /*   this->type = *new string (copiedAd.type);*/
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


//If the source territory does not belong to the player that issued the order, the order is invalid.
//If the target territory is not adjacent to the source territory, the order is invalid.

bool Advance::validate() {
    if (player->containsTerritory(fromTerritory) && map->isAdjacentTerritory(fromTerritory, toTerritory)) {
        cout<<"Advance is valid and can be executed.\n"<<endl;
        return true;
    }// &&map->isAdjacentTerritory(fromTerritory, toTerritory)
    else {
        cout<<"advance is invalid\n"<<endl;
        return false;
    }

}


// If the source and target territory both belong to the player that issued the order, the army units are moved from the source to the target territory.
// If the target territory belongs to another player than the player that issued the advance order, an attack is simulated when the order is executed. An attack is simulated by the following battle simulation mechanism:
//-- Each attacking army unit involved has 60% chances of killing one defending army. At the same time, each defending army unit has 70% chances of killing one attacking army unit.
//-- If all the defender's armies are eliminated, the attacker captures the territory. The attacking army units that survived the battle then occupy the conquered territory.
//-- A player receives a card at the end of his turn if they successfully conquered at least one territory during their turn.

void Advance::execute() {
    if(validate()){
        if(player->containsTerritory(fromTerritory) && player->containsTerritory(toTerritory))
            {
            fromTerritory->setNumArmies(fromTerritory->getNumArmies()-armies);
            toTerritory->setNumArmies(toTerritory->getNumArmies()+armies);
            cout<<"Advance is executed: Advance "<<armies<<" armies from "<<fromTerritory->getName()<<" to "<<toTerritory->getName()<<"\n"<<endl;
        }
        else{
            if(getAttackable()){
                while(toTerritory->getNumArmies()>0 || fromTerritory->getNumArmies()>0){
                    srand(time(NULL));
                    if(rand() % 10 < 6){
                        toTerritory->setNumArmies(toTerritory->getNumArmies()-1);
                        cout<<"Advance is executed: Each attacking army unit involved has 60% chances of killing one defending army. \n";
                    }
                    else if(rand() % 10 < 7){
                        fromTerritory->setNumArmies(fromTerritory->getNumArmies()-1);
                        armies--;
                        cout<<"Advance is executed: each defending army unit has 70% chances of killing one attacking army unit. \n";
                    }
                }
                if(toTerritory->getNumArmies()==0){
                    toTerritory->setPlayer(player->getPlayerId());
                    player->addTerritory(toTerritory);
                    toTerritory->setNumArmies(toTerritory->getNumArmies()+armies);
                    player->getHand()->addCard(card);
                }
            }

        }
    }
    else
        cout<<" advance cannot be executed\n"<<endl;
    Notify(this);
}


string Advance::stringToLog() {
    return "Advance executed";
}






/*********** BOMB ************/
// Bomb class

Bomb::Bomb() :Order(){
    setID(2);
    cout<<"The order"<<" "<<getOrderType()<<" is been placed"<<endl;
}

Bomb::Bomb(Player* player,Territory* targetTerritory) :Order(player){
    setID(2);
    this->player = player;
    this->targetTerritory = targetTerritory;
    cout<<"The order Bomb is been placed with issuer "<<player->getPlayerId()<<" targeting to the territory "<<targetTerritory->getName()<<"\n"<<endl;

}


//copy constructor
Bomb::Bomb(const Bomb& copiedBo) {
/*    this->type = *new string (copiedBo.type);*/
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


//• If the target belongs to the player that issued the order, the order is invalid.
//• If the target territory is not adjacent to one of the territory owned by the player issuing the order, then the order is invalid.
bool Bomb::validate() {
    if(!player->containsTerritory(targetTerritory)){
        cout<<"Bomb is valid and can be executed. \n"<<endl;
        return true;
    } else
        cout<<"the player cannot issue bomb order on own territories.\n"<<endl;
        return false;

}


//If the target belongs to an enemy player, half of the armies are removed from this territory.
void Bomb::execute() {
    if(validate()&&player->getHand()->getCardByType(bomb)&&getAttackable()){
        targetTerritory->setNumArmies(targetTerritory->getNumArmies()/2);
        cout<< "Bomb is executed: the armies on target Territory "<<targetTerritory->getName()<<"has been removed half by the issuer. \n"<<endl;
    } else
        cout<<" Bomb cannot be executed "<<"\n"<<endl;
    Notify(this);
}

string Bomb::stringToLog() {
    return "Bomb executed";
}










/*********** BLOCKADE ************/

//Blockade class
Blockade::Blockade() : Order() {
    setID(3);
    cout<<"The order"<<" "<<getOrderType()<<" is been placed"<<endl;
}
Blockade::Blockade(Player* player, Territory* targetTerritory) : Order(player){
    setID(3);
    this->targetTerritory = targetTerritory;
    this->player = player;
    cout<<"The order Blockade is been placed with issuer "<<player->getPlayerId()<<" targeting to the territory "<<targetTerritory->getName()<<"\n"<<endl;
}


//copy constructor
Blockade::Blockade(const Blockade& copiedBl) {
/*    this->type = *new string (copiedBl.type);*/
    this->player = copiedBl.player;
    this->targetTerritory = copiedBl.targetTerritory;
}

Blockade::~Blockade() {
    delete this->targetTerritory;
    delete this;
};

//assignment operator
Blockade& Blockade::operator = (const Blockade&Blo){
    Order::operator=(Blo);
    player = Blo.player;
    targetTerritory = Blo.targetTerritory;
    return *this;
};


//If the target territory belongs to an enemy player, the order is declared invalid.
bool Blockade::validate() {
    if(player->containsTerritory(targetTerritory)){
        cout<<"blockade is valid and can be executed.\n"<<endl;
        return true;
    }
    else
        cout<<"this territory is not belongs to the order issuer, the blockade is invalid"<<endl;
        return false;
}

//If the target territory belongs to the player issuing the order,
// the number of armies on the territory is doubled and the ownership of the territory is transferred to the Neutral player,
// which must be created if it does not already exist.
void Blockade::execute() {
    if(validate()&&player->getHand()->getCardByType(blockade)){
        targetTerritory->setNumArmies(targetTerritory->getNumArmies()*2);
        targetTerritory->neutralState();
        cout<<"Blockade is executed: The army on territory"<<targetTerritory->getName()<<"has been doubled ,and the ownership of this territory has been transferred to neutral.\n"<<endl;
    } else
        cout<<"Blockade cannot be executed"<<endl;
    Notify(this);
}


string Blockade::stringToLog() {
    return "Blockade executed";
}


/*********** AIRLIFT ************/
//Airlift class
Airlift::Airlift() :Order(){
    setID(4);
    cout<<"The order"<<" "<<getOrderType()<<" is been placed"<<endl;
}
Airlift::Airlift(Player* player,Territory* fromTerritory,Territory* toTerritory,unsigned int armies) : Order(player){
    setID(4);
    this->fromTerritory = fromTerritory;
    this->toTerritory = toTerritory;
    this->armies = armies;
    cout<<"The order Blockade is been placed with issuer "<<player->getPlayerId()<<" from territory "<<fromTerritory->getName()<<" to territory "<<toTerritory->getName()<<"\n"<<endl;
}

//copy constructor
Airlift::Airlift(const Airlift& copiedAir){
 /*   this->type = *new string (copiedAir.type);*/
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


//• The target territory does not need to be adjacent to the source territory.
//• If the source or target does not belong to the player that issued the order, the order is invalid.
bool Airlift::validate() {
    if(player->containsTerritory(fromTerritory)&&player->containsTerritory(toTerritory)){
        cout<<"airlift is valid and can be executed\n"<<endl;
        return true;
    } else
        cout<<"The airlift order is invalid";
        return false;
}

//If both the source and target territories belong to the player that issue the airlift order,
// then the selected number of armies is moved from the source to the target territory.
void Airlift::execute() {
        if(validate()&&player->getHand()->getCardByType(airlift)){
            fromTerritory->setNumArmies(fromTerritory->getNumArmies()-armies);
            toTerritory->setNumArmies(toTerritory->getNumArmies()+armies);
            cout<<"Airlift is executed: The player has moved "<<armies<<" armies from the source territory "<<fromTerritory->getName()<<" to the target territory "<<toTerritory->getName()<<"\n"<<endl;
        }
        else
            cout<<"No airlift card is creating or airlift order is invalid"<<endl;
    Notify(this);
}

string Airlift::stringToLog(){
    return "Airlist executed";
}





/*********** NEGOTIATE ***************/
//Negotiate class
Negotiate::Negotiate() :Order(){
    setID(5);
    cout<<"The order"<<" "<<getOrderType()<<" is been placed"<<endl;
}

Negotiate::Negotiate(Player* player,Player* targetPlayer) : Order(player){
    setID(5);
    this->player = player;
    this->targetPlayer = targetPlayer;
    cout<<"The order Negotiate is been placed by player "<<player->getPlayerId()<<" to target player "<<targetPlayer->getPlayerId()<<"\n"<<endl;
}
Negotiate::~Negotiate() {
    delete this->player;
    delete this->targetPlayer;
    delete this;
};

//copy constructor
Negotiate::Negotiate(const Negotiate& copiedNe){
 /*   this->type = *new string (copiedNe.type);*/
    this->player = copiedNe.player;
    this->targetPlayer = copiedNe.targetPlayer;
}
//assignment operator
Negotiate& Negotiate::operator = (const Negotiate&Neo){
    Order::operator=(Neo);
    player = Neo.player;
    targetPlayer = Neo.targetPlayer;
    return *this;
};


//If the target territory belongs to an enemy player, the order is declared invalid.
bool Negotiate::validate() {
    if(targetPlayer->getPlayerId() == player->getPlayerId()){

        cout<<"Target player cannot be the Negotiate Issuer\n"<<endl;
        return false;
    }
    else{
        cout<<"negotiate is valid and can be executed\n"<<endl;
        return true;
    }
}

//If the target territory belongs to the player issuing the order,
// the number of armies on the territory is doubled and the ownership of the territory is transferred to the Neutral player,
// which must be created if it does not already exist.
void Negotiate::execute() {
    if(validate()&&player->getHand()->getCardByType(diplomacy)){
    //Todo: what should be considered as attack?
        if(player->containsOrder("bomb")||player->containsOrder("advance")){
            setAttackable(false);
            cout<<"Negotiate is executed: The Negotiate has been executed by player "<<player->getPlayerId()<<" targeting to player "<<targetPlayer->getPlayerId()<<". No attack can be executed between them\n"<<endl;
        }
        else if(targetPlayer->containsOrder("bomb")||targetPlayer->containsOrder("advance")){
            Order *targetBomb = targetPlayer->getOrderbyType("bomb");
            targetBomb->setAttackable(false);
            Order *targetAdvance = targetPlayer->getOrderbyType("advance");
            targetAdvance->setAttackable(false);
            cout<<"Negotiate is executed: The Negotiate has been executed by player "<<player->getPlayerId()<<" targeting to player "<<targetPlayer->getPlayerId()<<". No attack can be executed between them\n"<<endl;
        }
    }
    else
        cout<<"The Negotiate order cannot be executed\n"<<endl;
    Notify(this);
}

string Negotiate::stringToLog() {
    return "Negotiate executed";
}


/*********** ORDER LIST ************/
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
    Notify(this);
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
            cout << "The order " << order->getOrderType() << " has been removed from the list" << endl;
            return;
        }
    }
}



//move order from origin position to the target position
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

void Orderslist::printOrderlist(){
    auto it = orderlist.begin();
    for (; it != orderlist.end(); it++)
    {
        cout << (*it)->getOrderType() << " " << endl;
    }
    cout << endl;

 }

// string to log when addOrder from OrderList has been called.
string Orderslist::stringToLog() {
//    string orderType = order.getOrderType();
//    vector<Order*>::iterator it = orderlist.end();
//    string lastOrder = (*it)->getOrderType();
//    string toString = "OrderList add order" + it;
    return "OrderList add order: ";
}


