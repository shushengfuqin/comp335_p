//
// Created by Mia Yan on 8/2/2022.
//

#include "Player.h"

//Player constructor
Player::Player() {
    //player owns a hand
    playerHand = new Hand();
    //player owns a territory list
    playerTerritoryList = new vector<Territory*>;
    //player owns an attack territory list
    playerDefendList = new vector<Territory*>();
    //player owns a defend territory list
    playerAttackList = new vector<Territory*>();
    //player owns an order list
    orderList = new OrderList();
}

//Player destructor
Player::~Player(){
    delete playerHand;
    for(int i = 0; i<playerTerritoryList->size();i++){
        delete playerTerritoryList->at(i);
    }
    delete playerTerritoryList;
    for(int i = 0; i<playerAttackList->size();i++){
        delete playerAttackList->at(i);
    }
    delete playerAttackList;
    for(int i = 0; i<playerDefendList->size();i++){
        delete playerDefendList->at(i);
    }
    delete playerDefendList;
    delete orderList;
}

//Player copy constructor
//it should call the copy constructor of the other classes
//to avoid copy the pointer
Player::Player(const Player &player1) {
    playerHand = player1.playerHand;
    playerTerritoryList = player1.playerTerritoryList;
    playerDefendList = player1.playerDefendList;
    playerAttackList = player1.playerAttackList;
    orderList = player1.orderList;
}


//Player assignment operator overload
//it should call the copy constructor of the other classes
//to avoid copy the pointer
Player&Player::operator=(const Player& player1) {
    playerHand = player1.playerHand;
    playerTerritoryList = player1.playerTerritoryList;
    playerDefendList = player1.playerDefendList;
    playerAttackList = player1.playerAttackList;
    orderList = player1.orderList;
}


//Player stream insertion
ostream&::operator<<(ostream &os, const Player &player) {
    os<<"Hi I am player"<<endl;
}


//once a player want to attack a territory, the territory
//is added to the attack list
void Player::attackTerritory(Territory *territory) {
    //add territory to the attack list
    playerAttackList->push_back(territory);
}

//once some other player want to attack a territory, the territory
//is added to the defend list
void Player::defendTerritory(Territory *territory) {
    //add territory to the defended list
    playerDefendList->push_back(territory);
}

//assignment a territory to the player class
void Player::addTerritory(Territory *territory) {
    //add territory to the list
    playerTerritoryList->push_back(territory);
}

//the player attack action, returns a list of territories being attacked
vector<Territory*>* Player::toAttack() {
    //for print out the list in the console
    std::cout << '\n' << "Player's Attack List:" << '\n'<<endl;
    for (int i = 0; i < playerAttackList->size(); ++i) {
        cout << playerAttackList->at(i)->getName() << '\n'<<endl;
    }

    return playerAttackList;

}

//the player defend action, returns a list of territories being defended
vector<Territory*>* Player::toDefend() {

    //print out the defend list in the console
    std::cout << '\n' << "Player's Defend List:" << '\n'<<endl;

    for (int i = 0; i < playerDefendList->size(); ++i) {
        cout << playerDefendList->at(i)->getName() << '\n'<<endl;
    }

    return playerDefendList;
}

vector<Territory*>* Player::displayTerritory() {

    //print out all territorist of this play in the list in the console
    std::cout << '\n' << "Player's Territory List:" << '\n'<<endl;

    for (int i = 0; i < playerTerritoryList->size(); ++i) {
        cout << playerTerritoryList->at(i)->getName() << '\n'<<endl;
    }

    return playerTerritoryList;
}

int Player::getHandLimit() {

    //display the number of hand of this player
    cout << '\n' << "Hand Limit for this player: " << '\n'<<endl;
    cout << playerHand->getHandLimit() << '\n'<<endl;

}

void Player::issueOrders(Order *order) {
    //add the order in the order list
    orderList->add(order);


}