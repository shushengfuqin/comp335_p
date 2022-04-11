//
// Created by deepbluecanada on 2022-04-08.
//

#include "PlayerStrategies.h"

/**
 *  PlayerStrategy abstract
 */
//Default constructor
PlayerStrategy::PlayerStrategy() {
}

//Destructor
PlayerStrategy::~PlayerStrategy(){
    delete p;
}

void PlayerStrategy::setPlayer(Player* p){
    this->p = p;
}

void PlayerStrategy::setStrategyName(string name) {
    strategy_name = name;
}

string PlayerStrategy::getStrategyName() const {
    return strategy_name;
}
/**
*  Player Strat Human
*/
Human::Human(): PlayerStrategy() {
    setStrategyName("Human");
}

// human will do what's in the issueorder in the gameeng file's issue order
void Human::issueOrder(Player*& i, Map* generatedMap) {

}


vector<Territory *>* Human::toDefend(Map* Map, Player &player) {
    cout << "Human to defend" << endl;
    return {};
}
vector<Territory *>* Human::toAttack() {
    return p->getAttackList();
}
//
//vector<Territory *>* Human::toDefend() {
//    return vector<Territory *>*();
//}


/**
 * Player Strat Aggressive
 */

//Default Constructor
Aggressive::Aggressive(): PlayerStrategy() {
    setStrategyName("Aggressive");
}

// it will only issue deploy and advance to attack enemy territory
void Aggressive::issueOrder(Player*& i, Map* generatedMap) {

}

vector<Territory *> Aggressive::toAttack(Map* Map, Player &player) {
    cout << "Aggressive to attack" << endl;
    return {};
}

//vector<Territory *>* Aggressive::toAttack() {
//    return vector<Territory *>*();
//}
//
//vector<Territory *>* Aggressive::toDefend() {
//    return vector<Territory *>*();
//}
vector<Territory *> Aggressive::toDefend(Map* Map, Player &player) {
    cout << "Aggressive to defend" << endl;
    return {};
}

/**
*  Player Strat Benevolent
*/

//Default Constructor
Benevolent::Benevolent(): PlayerStrategy() {
    setStrategyName("Benevolent");
}

// It will only issue deploy and advance to own territory
void Benevolent::issueOrder(Player*& i, Map* generatedMap) {

}

vector<Territory *> Benevolent::toAttack(Map* Map, Player &player) {
    cout << "Benevolent to attack" <<endl;
    return {};
}

vector<Territory *> Benevolent::toDefend(Map* Map, Player &player) {
    cout << "Benevolent to defend" <<endl;
    return {};
}
//vector<Territory *>* Benevolent::toAttack() {
//    return vector<Territory *>();
//}
//
//vector<Territory *> Benevolent::toDefend() {
//    return vector<Territory *>*();
//}

/**
*  Player Strat Neutral
*/

//Default Constructor
Neutral::Neutral(): PlayerStrategy() {
    setStrategyName("Neutral");
}


// Does not thing
void Neutral::issueOrder(Player*& i, Map* generatedMap) {

}

vector<Territory *> Neutral::toAttack(Map* Map, Player &player) {
    cout << "Neutral to attack" << endl;
    return {};
}

vector<Territory *> Neutral::toDefend(Map* Map, Player &player) {
    cout << "Neutral to defend" << endl;
    return {};
}
//vector<Territory *>* Neutral::toAttack() {
//    return vector<Territory *>*();
//}
//
//vector<Territory *> Neutral::toDefend() {
//    return vector<Territory *>*();
//}

/**
*  Player Strat Cheater
*/

//Default Constructor
Cheater::Cheater(): PlayerStrategy() {
    setStrategyName("Cheater");
}

// special issueOrder. add a cheat order for him which will get all his adjacent territory and change the territory to the cheaters
void Cheater::issueOrder(Player*& i, Map* generatedMap) {

}

vector<Territory *> Cheater::toAttack(Map* Map, Player &player) {
    cout << "Cheater to attack" << endl;
    return {};
}

vector<Territory *> Cheater::toDefend(Map* Map, Player &player) {
    cout << "Cheater to defend" << endl;
    return {};
}
//vector<Territory *>* Cheater::toAttack() {
//    return vector<Territory *>();
//}
//
//vector<Territory *>* Cheater::toDefend() {
//    return vector<Territory *>();
//}