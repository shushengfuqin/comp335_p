//
// Created by Mia Yan on 8/2/2022.
//

#include "Player.h"

//Player constructor
Player::Player(){
    //player owns a hand
    playerHand =new Hand();
    //player owns a territory list
    playerTerritoryList= new vector<Territory>;
    //player owns an attack territory list
    playerDefendList=new vector<Territory>();
    //player owns a defend territory list
    playerAttackList=new vector<Territory>();
    //player owns an order list
    orderList=new OrderList();

}
//once a player want to attack a territory, the territory
//is added to the attack list
void Player::attackTerritory(Territory *territory){
    playerAttackList->push_back(*territory);
    //if this terr belongs to someone
    //then add territory to that player's defend list
}
//once some other player want to attack a territory, the territory
//is added to the defend list
void Player::defendTerritory(Territory *territory){
    playerDefendList->push_back(*territory);
}
void Player::addTerritory(Territory *territory){
    playerTerritoryList->push_back(*territory);
}
vector<Territory> Player::toAttack() {
    std::cout << '\n'<< "Player's Attack List:"<<'\n';
    for(int i=0; i<playerAttackList->size();++i){
        cout<<playerAttackList->at(i).getName()<<'\n';
    }

    return *playerAttackList;

}

vector<Territory> Player::toDefend() {
    std::cout << '\n'<<"Player's Defend List:"<<'\n';

    for(int i=0; i<playerDefendList->size();++i){
        cout<<playerDefendList->at(i).getName()<<'\n';
    }

    return *playerDefendList;
}

vector<Territory> Player::displayTerritory() {
    std::cout << '\n'<<"Player's Territory List:"<<'\n';

    for(int i=0; i<playerTerritoryList->size();++i){
        cout<<playerTerritoryList->at(i).getName()<<'\n';
    }

    return *playerTerritoryList;
}

int Player::getHandLimit(){
    cout<<'\n'<<"Hand Limit for this player: "<<'\n';
    cout<<playerHand->getHandLimit()<<'\n';

}

void Player::issueOrders(Order* order) {
    orderList->add(order);


}