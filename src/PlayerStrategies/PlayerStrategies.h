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
    PlayerStrategy(); // default constructor
    ~PlayerStrategy(); // destructor
    void setPlayer(Player* p);
    virtual void issueOrder(Player *&i, Map *generatedMap, bool deployOrNot, vector<Player *> *playerList) = 0;
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
};

/**
 *  Player strat Aggressive
 */
class Aggressive: public PlayerStrategy {
public:
    Aggressive(); // default constructor
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
};

/**
 *  Player strat Benevolent
 */
class Benevolent: public PlayerStrategy {
public:
    Benevolent();
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
};

/**
 *  Player strat Neutral
 */
class Neutral: public PlayerStrategy {
public:
    Neutral(); // default constructor
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
};

/**
 *  Player strat Cheater
 */
class Cheater: public PlayerStrategy {
public:
    Cheater();  // default constructor
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
};

/**
 *  Player strat Neutral
 */
class Gaia: public PlayerStrategy {
public:
    Gaia(); // default constructor
    void issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) override;
};

#endif //COMP335_P_PLAYERSTRATEGIES_H
