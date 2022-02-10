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
    void attackTerritory(Territory *territory);
    void defendTerritory(Territory *territory);
    void issueOrders();
    int getHandLimit();


private:
    Node node;
    vector<Territory>* playerTerritoryList;
    vector<Territory>* playerDefendList;
    vector<Territory>* playerAttackList;
    Hand *playerHand;



};

#endif //COMP335_P_PLAYER_H
