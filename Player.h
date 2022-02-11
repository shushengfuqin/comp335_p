//
// Created by Mia Yan on 8/2/2022.
//

#ifndef COMP335_P_PLAYER_H
#define COMP335_P_PLAYER_H
#include <istream>
#include "Map.h"
#include "Cards.h"
#include "Orders.h"
#include "vector"
using namespace std;

class Player{
public:
    Player();
    int numAttack;
    int numDefend;
    vector<Territory> toAttack();
    vector<Territory> toDefend();
    vector<Territory> displayTerritory();
    void attackTerritory(Territory *territory);
    void defendTerritory(Territory *territory);
    void addTerritory(Territory *territory);
    void issueOrders(Order* order);
    int getHandLimit();
    OrderList* orderList;


private:
    vector<Territory>* playerTerritoryList;
    vector<Territory>* playerDefendList;
    vector<Territory>* playerAttackList;
    Hand *playerHand;



};

#endif //COMP335_P_PLAYER_H
