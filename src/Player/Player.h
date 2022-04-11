//
// Created by Mia Yan on 8/2/2022.
//

#ifndef COMP335_P_PLAYER_H
#define COMP335_P_PLAYER_H
#include <istream>
#include "../Map/Map.h"
#include "../Cards/Cards.h"
#include "../Order/Orders.h"
#include "../PlayerStrategies/PlayerStrategies.h"
#include "vector"
using namespace std;

struct Order;
class Orderslist;
class Territory;
class Map;
class PlayerStrategy;

class Player{
public:

    string getPlayerStrategyString();
    void setStrategyString(string strategyString);
    void setStrategy(PlayerStrategy *newStrategy);
    PlayerStrategy* getPlayerStrategy();
    Player();
    Player(string name);
    ~Player();
    Player(const Player &player1);
    Player& operator=(const Player& player);
    friend std::ostream& operator<<(ostream &os, const Player& player);
    vector<Territory*>* toAttack(Map *map);
    vector<Territory*>* toDefend();

    // getter for the component in the constructor
    vector<Territory*>* getTerritoryList();
    vector<Territory*>* getAttackList();
    vector<Territory*>* getDefendList();
    Territory* getTerritoryByName(string name,vector<Territory*>* territoryList);

    void displayTerritory(vector<Territory*>*);
    void attackTerritory(Territory *territory);
    void defendTerritory(Territory *territory);
    void addTerritory(Territory *territory);

    void removeTerritory(Territory *territory);
    void cancelAttack(Territory *territory);
    void cancelDefend(Territory *territory);
    void calculateArmy(Map *map);
    void switchTerritories(Territory *territory,Player *player1, Player *player2);
    void issueOrders(Player*& i, Map* generatedMap);
    int getHandLimit();
    Orderslist* getOrderList();
    void setPlayerId(int id);
    int getPlayerId();
    void setPlayerName(string name);
    string getPlayerName();
    void calculateBonus(Map *map);
    int getPlayerNumOfTerritoriesInContinent(int id);
    int getArmyNum();
    int addArmyNum(int number);
    bool containsTerritory(Territory *territory);
    bool canAttack(Territory *territory);
    bool alreadyOwn(Territory *territory);
    bool containTerritoryByName(string territoryName,vector<Territory*>* territoryList);
    int removeArmyNum(int number);
    Hand *getHand(){ return playerHand ;};
    bool containsOrder(string orderType);

    Order *getOrderbyType(string orderType);
private:
    vector<Territory*>* playerTerritoryList;
    vector<Territory*>* playerDefendList;
    vector<Territory*>* playerAttackList;
    Hand *playerHand;
    Orderslist* orderList;
    int armyNum;
    int playerId;
    string playerName;
    PlayerStrategy *strategy;
    string strategyString;
};

#endif //COMP335_P_PLAYER_H
