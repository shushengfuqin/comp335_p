//
// Created by deepbluecanada on 2022-04-08.
//

#ifndef COMP335_P_PLAYERSTRATEGIES_H
#define COMP335_P_PLAYERSTRATEGIES_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../Player/Player.h"
#include "../Map/Map.h"

using namespace std;
class Player;
class Territory;
class Map;
class PlayerStrategy {
public:
//    Player* p;
    PlayerStrategy(); // default constructor
    ~PlayerStrategy(); // destructor
    void setPlayer(Player* p);
    virtual void issueOrder(Player *&i, Map *generatedMap, bool deployOrNot, vector<Player *> *playerList) = 0;
//    virtual vector <Territory*>* toAttack(Map* Map, Player &player) = 0;
//    virtual vector <Territory*>* toDefend(Map* Map, Player &player) = 0;
    void setStrategyName(string name); // Mutator
    string getStrategyName() const; // Accesor
private:
    string strategy_name;
  };

/**
 * Player strat human
 */
class Human: public PlayerStrategy {
public:
    Human(); // default constructor
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
//    vector <Territory*>* toAttack(Map* Map, Player &player) override;
//    vector <Territory*>* toDefend(Map* Map, Player &player) override;
//    vector <Territory*>* toAttack() override;
//    vector <Territory*>* toDefend() override;
//    vector<Territory*> *toAttack();
};

/**
 *  Player strat Aggressive
 */
class Aggressive: public PlayerStrategy {
public:
    Aggressive(); // default constructor
//    vector <Territory*>* toAttack() override;
//    vector <Territory*>* toDefend() override;
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
//    vector <Territory*> toAttack(Map* Map, Player &player) override;
//    vector <Territory*> toDefend(Map* Map, Player &player) override;
};

/**
 *  Player strat Benevolent
 */
class Benevolent: public PlayerStrategy {
public:
    Benevolent();
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
//    vector <Territory*>* toAttack(Map* Map, Player &player) override;
//    vector <Territory*>* toDefend(Map* Map, Player &player) override;
//    vector <Territory*>* toAttack() override;
//    vector <Territory*>* toDefend() override;
};

/**
 *  Player strat Neutral
 */
class Neutral: public PlayerStrategy {
public:
    Neutral(); // default constructor
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
//    vector <Territory*> toAttack(Map* Map, Player &player) override;
//    vector <Territory*> toDefend(Map* Map, Player &player) override;
//    vector <Territory*>* toAttack() override;
//    vector <Territory*>* toDefend() override;
};

/**
 *  Player strat Cheater
 */
class Cheater: public PlayerStrategy {
public:
    Cheater();  // default constructor
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
//    vector <Territory*> toAttack(Map* Map, Player &player) override;
//    vector <Territory*> toDefend(Map* Map, Player &player) override;
//    vector <Territory*>* toAttack() override;
//    vector <Territory*>* toDefend() override;
};

/**
 *  Player gaia
 */
class Gaia: public PlayerStrategy {
public:
    Gaia(); // default constructor
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
//    vector <Territory*> toAttack(Map* Map, Player &player) override;
//    vector <Territory*> toDefend(Map* Map, Player &player) override;
//    vector <Territory*>* toAttack() override;
//    vector <Territory*>* toDefend() override;
};

#endif //COMP335_P_PLAYERSTRATEGIES_H
