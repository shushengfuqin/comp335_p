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
    vector<Territory*>* getTerritoryList();
    vector<Territory*>* getAttackList();
    vector<Territory*>* getDefendList();

    void attackTerritory(Territory *territory);
    void defendTerritory(Territory *territory);
    void addTerritory(Territory *territory);
    void removeTerritory(vector<Territory*>* territoryList,Territory *territory);
    void issueOrders(Order* order);
    int getHandLimit();
//    bool isTerritorySame(Territory *territory1, Territory *territory2);



private:
    vector<Territory*>* playerTerritoryList;
    vector<Territory*>* playerDefendList;
    vector<Territory*>* playerAttackList;
    Hand *playerHand;
    Orderslist* orderList;
    int armyNum;

};

#endif //COMP335_P_PLAYER_H
