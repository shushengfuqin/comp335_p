//
// Created by Mia Yan on 8/2/2022.
//

#ifndef COMP335_P_PLAYER_H
#define COMP335_P_PLAYER_H
#include <istream>
#include "../Map/Map.h"
#include "../Cards/Cards.h"
#include "../Order/Orders.h"
#include "vector"
using namespace std;

class Player{
public:
    Player();
    ~Player();
    Player(const Player &player1);
    Player& operator=(const Player& player);
    friend std::ostream& operator<<(ostream &os, const Player& player);
    vector<Territory*>* toAttack();
    vector<Territory*>* toDefend();
    vector<Territory*>* displayTerritory();
    void attackTerritory(Territory *territory);
    void defendTerritory(Territory *territory);
    void addTerritory(Territory *territory);
    void issueOrders(Order* order);
    int getHandLimit();



private:
    vector<Territory*>* playerTerritoryList;
    vector<Territory*>* playerDefendList;
    vector<Territory*>* playerAttackList;
    Hand *playerHand;
    Orderslist* orderList;

};

#endif //COMP335_P_PLAYER_H
