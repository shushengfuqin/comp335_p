//
// Created by Mia Yan on 8/2/2022.
//
#include <ostream>
#include "Player.h"

using namespace std;

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
    orderList = new Orderslist();
    int playerId=0;
    armyNum = 50;
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
    this->playerHand=player1.playerHand;
    for(int i =0;i<player1.playerTerritoryList->size();i++){
        this->playerTerritoryList->push_back(player1.playerTerritoryList->at(i));
    }

    for(int i =0;i<player1.playerDefendList->size();i++){
        this->playerDefendList->push_back(player1.playerDefendList->at(i));
    }

    for(int i =0;i<player1.playerAttackList->size();i++){
        this->playerAttackList->push_back(player1.playerAttackList->at(i));
    }

    for(int i =0;i<player1.orderList->getOrderList()->size();i++){
        this->orderList->setOrderList(player1.orderList->getOrderList()->at(i));
    }

    this->playerId = player1.playerId;
}


//Player assignment operator overload
//it should call the copy constructor of the other classes
//to avoid copy the pointer
Player&Player::operator=(const Player& player1) {
    this->playerHand=player1.playerHand;
    for(int i =0;i<player1.playerTerritoryList->size();i++){
        this->playerTerritoryList->push_back(player1.playerTerritoryList->at(i));
    }

    for(int i =0;i<player1.playerDefendList->size();i++){
        this->playerDefendList->push_back(player1.playerDefendList->at(i));
    }

    for(int i =0;i<player1.playerAttackList->size();i++){
        this->playerAttackList->push_back(player1.playerAttackList->at(i));
    }

    for(int i =0;i<player1.orderList->getOrderList()->size();i++){
        this->orderList->setOrderList(player1.orderList->getOrderList()->at(i));
    }


    this->playerId = player1.playerId;

    return *this;
}


//Player stream insertion
std::ostream &operator<<(ostream &os, const Player &player) {
    os<<"Hi I am player :"<<player.playerId<<endl;
    return os;
}


//once a player want to attack a territory, the territory
//is added to the attack list
void Player::attackTerritory(Territory *territory) {
    //validating if the territory already in the list
    if (std::count(playerAttackList->begin(), playerAttackList->end(), territory) ) {
        std::cout << "Element already existed, cannot be added to the player "<<playerId<<"'s attack list: "<<territory->getName()<<endl;
    }
    else {
        //add territory to the attack list
        playerAttackList->push_back(territory);
        std::cout<<"Element has been added to the player "<<playerId<<"'s attack list: "<<territory->getName()<<endl;
    }

}

//once some other player want to attack a territory, the territory
//is added to the defend list
void Player::defendTerritory(Territory *territory) {

    //validating if the territory already in the list
    if (std::count(playerDefendList->begin(), playerDefendList->end(), territory) ) {
        std::cout << "Element already existed, cannot be added to the player "<<playerId<<"'s defend list: "<<territory->getName()<<endl;
    }
    else {
        //add territory to the defended list
        playerDefendList->push_back(territory);
        std::cout<<"Element has been added to the player "<<playerId<<"'s defend list: "<<territory->getName()<<endl;
    }
}

//assignment a territory to the player class
void Player::addTerritory(Territory *territory) {
    //check if the territory already in the


    //validating if the territory already in the list
    if (std::count(playerTerritoryList->begin(), playerTerritoryList->end(), territory) ) {
        std::cout << "Element already existed, cannot be added to the defend list: "<<territory->getName()<<endl;
    }
    else {
        //add territory to the list
        playerTerritoryList->push_back(territory);
        std::cout<<"Element has been added to the player's territories list: "<<territory->getName()<<endl;
    }
}

//add an assignment to remove territories
void Player::removeTerritory(Territory *territory) {
    //validating if the territory already in the list
    if (std::count(playerTerritoryList->begin(), playerTerritoryList->end(), territory) ) {
        //remove the territory from the list
        playerTerritoryList->erase(std::remove(playerTerritoryList->begin(),playerTerritoryList->end(),territory),playerTerritoryList->end());

        std::cout << "Element removed from the player "<<playerId<<"'s Territory list: "<<territory->getName()<<endl;

    }
    else {

        std::cout<<"The player does not have such territory, so the remove from player "<<playerId<<"'s territory list failed: "<<territory->getName()<<endl;
    }


}

//cancel the attack
void Player::cancelAttack(Territory *territory) {
    //validating if the territory already in the list
    if (std::count(playerAttackList->begin(), playerAttackList->end(), territory) ) {
        //remove the territory from the list
        playerAttackList->erase(std::remove(playerAttackList->begin(),playerAttackList->end(),territory),playerAttackList->end());

        std::cout << "Element removed from the player "<<playerId<<"'s Attacking list: "<<territory->getName()<<endl;

    }
    else {

        std::cout<<"The player "<<playerId<<" didn't want to attack the following territory, so the remove failed: "<<territory->getName()<<endl;
    }


}

bool Player::containsTerritory(Territory *territory) {
    if (std::count(playerTerritoryList->begin(), playerTerritoryList->end(), territory) ) {
        cout<<"player has this territory"<<endl;
        return true;
    }
    else {
        cout<<"player does not have this territory"<<endl;
       return true;
    }
}

//cancel the defend
void Player::cancelDefend(Territory *territory) {
    //validating if the territory already in the list
    if (std::count(playerDefendList->begin(), playerDefendList->end(), territory) ) {
        //remove the territory from the list
        playerDefendList->erase(std::remove(playerDefendList->begin(),playerDefendList->end(),territory),playerDefendList->end());

        std::cout << "Element removed from the player "<<playerId<<"'s defending list: "<<territory->getName()<<endl;

    }
    else {

        std::cout<<"The player "<<playerId<<" did not need to defend the following territory, so the remove failed: "<<territory->getName()<<endl;
    }


}

//the player attack action, returns a list of territories being attacked
vector<Territory*>* Player::toAttack() {

    return playerAttackList;

}

//the player defend action, returns a list of territories being defended
vector<Territory*>* Player::toDefend() {

    return playerDefendList;
}

void Player::displayTerritory(vector<Territory*>* territoryList) {

    //print out all territory of this player in the list in the console
    std::cout << '\n' << "Player "<<playerId<<"'s Territory List:" << '\n'<<endl;

    for (int i = 0; i < territoryList->size(); ++i) {
        cout << territoryList->at(i)->getName() << '\n'<<endl;
    }

}

int Player::getHandLimit() {

    //display the number of hand of this player
    cout << '\n' << "Hand Limit for this player "<<playerId<<": " << '\n'<<endl;
    cout << playerHand->getHandLimit() << '\n'<<endl;

    return playerHand->getHandLimit();

}

void Player::issueOrders(Order *order) {
    //add the order in the order list

    orderList->setOrderList(order);

}



//getTerritoryList
vector<Territory*>* Player::getTerritoryList() {

    return playerTerritoryList;
}

//getAttackList
vector<Territory*>* Player::getAttackList() {

    return playerAttackList;
}

//getDefendList
vector<Territory*>* Player::getDefendList() {

    return playerDefendList;
}

void Player::setPlayerId(int id){
    playerId=id;

}

int Player::getPlayerId(){

    return playerId;
}

int Player::getArmyNum() {
    return armyNum;
}

int Player::addArmyNum(int number) {
    armyNum+=number;
    return armyNum;
}

//int Player::removeArmyNum(int number) {
//    armyNum-=number;
//    return armyNum;
//}
//
//int Player::updateArmyNum(int continentBonus) {
//    //need to update the code
//    return armyNum;
//}
//
//switchTerritories between two player, remove from player 1, add to player 2.
void Player::switchTerritories(Territory *territory, Player *player1,Player *player2) {
    player1->removeTerritory(territory);
    player2->addTerritory(territory);

    cout<<"the territory :"<<territory->getName()<<"has been removed from player "<<player1->getPlayerId()<<" and added to player "<<player2->getPlayerId()<<endl;
}

int Player::getPlayerNumOfTerritoriesInContinent(int id) {
    int numOfTerritories = 0;
    for (int index = 0; index < playerTerritoryList->size(); index++) {
        if (playerTerritoryList->at(index)->getContinentId() == id) {
            numOfTerritories++;
        }
    }
    return numOfTerritories;

}


void Player::calculateBonus(Map *map) {
    cout << "Init" << endl;
    int continentNum=map->getLastContinentId();
    for(int i=1;i<=continentNum;i++){
        cout << "for loop " << i << endl;
        int x= this->getPlayerNumOfTerritoriesInContinent(i);
        int y=map->getNumOfTerritoriesInContinent(i);

        if(x==y){
            cout<<"player have one complete continent: "<<endl;
            armyNum+=map->getArmyContinentBonus(i);
        }
    }

}

void Player::calculateArmy(Map *map){
    armyNum+=playerTerritoryList->size()/3;
    this->calculateBonus(map);
    if(armyNum<3){
        armyNum=3;
    }
    cout << "Army Value is ..." << armyNum <<endl;

}



