//
// Created by yuxin wang on 2022/2/3.
//

#ifndef COMP335_P_ORDERS_H
#define COMP335_P_ORDERS_H

#include <iostream>
#include <vector>
#include "../Map/Map.h"
#include "../Player/Player.h"
#include "../Cards/Cards.h"

using namespace std;
class Player;
class Territory;
class Map;
class Card;
class Deck;
class Hand;


struct Order
{
public:
    //constructor & destructor
    Order();
    Order(Player* player);
    ~Order();
    Order(const Order& copiedO);
    Order& operator = (const Order &O);
    friend ostream & operator <<(ostream &out, const Order &o);
    friend istream & operator >> (istream &in,  Order &o);

    virtual bool validate() = 0 ;

    virtual void execute() = 0;

    void setID(int i);

   string getOrderType();

    Map* map;
    Player *player;
    bool getAttackable(){return attackable;};
    void setAttackable(bool isAttackable){attackable = isAttackable; };
    const Player* getOrderIssuer();
    void setOrderIssuer(Player *issuer);
private:
    int id;
    bool valid;
    vector<string> orders = {"deploy","advance","bomb","blockade","airlift","negotiate"};
    bool attackable = true;

};


struct Deploy : public Order{
public:
    Deploy();
    Deploy(Player* player,Territory* targetTerritory,unsigned int armies);
    ~Deploy();
    Deploy(const Deploy& copiedDe);
    Deploy& operator = (const Deploy &Do);
    virtual bool validate();
    virtual void execute();

private:
    Territory* targetTerritory;
    unsigned int armies;


};
struct Bomb : public Order {
public:


    Bomb();
    Bomb(Player* player,Territory* targetTerritory);
    ~Bomb();
    Bomb(const Bomb& copiedBo);
    Bomb& operator = (const Bomb &Bo);
    virtual bool validate();
    virtual void execute();


private:
    Territory* targetTerritory;

};





struct Advance : public Order{
public:

    Advance();
    Advance(Player* player, Territory* fromTerritory,Territory* toTerritory,unsigned int armies);
    ~Advance();
     Advance(const Advance& copiedAd);
    Advance& operator = (const Advance &Ao);
    virtual bool validate();
    virtual void execute();


private:
    Territory* fromTerritory;
    Territory* toTerritory;
    unsigned int armies;

    Card *card = new Card();
};

struct Blockade : public Order{
public:

    Blockade();
    Blockade(Player* player, Territory* targetTerritory);
    ~Blockade();
    Blockade(const Blockade& copiedBl);
    Blockade& operator = (const Blockade &Blo);
    virtual bool validate();
    virtual void execute();

private:
    Territory* targetTerritory;
};

struct Airlift : public Order{
public:

    Airlift() ;
    Airlift(Player* player,Territory* fromTerritory,Territory* toTerritory,unsigned int armies);
    ~Airlift();
    Airlift(const Airlift& copoedAir);
    Airlift& operator = (const Airlift &Airo);
    virtual bool validate();
    virtual void execute();

private:
    Territory* fromTerritory;
    Territory* toTerritory;
    unsigned int armies;

};

struct Negotiate : public Order{
public:


    Negotiate() ;
    Negotiate(Player* player,Player* targetPlayer);
    ~Negotiate();
    Negotiate(const Negotiate& copiedNe);
    Negotiate& operator = (const Negotiate &Neo);
    virtual bool validate();
    virtual void execute();

private:
    Player* targetPlayer;

};







class Orderslist {
public:

    Orderslist();
    Orderslist(const Orderslist& copiedOl);
    ~Orderslist();
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
