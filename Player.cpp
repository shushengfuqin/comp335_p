//
// Created by Mia Yan on 8/2/2022.
//

#include "Player.h"

Player::Player(){
    Node *node;
    playerHand=new Hand();
    playerTerritoryList = new vector<Territory>();
    playerDefendList=new vector<Territory>();
    playerAttackList=new vector<Territory>();


}

void Player::attackTerritory(Territory *territory){
    numAttack=playerAttackList->size();
    playerAttackList->push_back(*territory);
}
void Player::defendTerritory(Territory *territory){
    numDefend=playerDefendList->size();
    playerDefendList->push_back(*territory);
}
vector<Territory> Player::toAttack() {
    std::cout << "Player's Attack List:"<<'\n';
    for(int i=0; i<=numAttack;++i)
        cout<<&playerAttackList[i]<<'\n';
    return *playerAttackList;

}

vector<Territory> Player::toDefend() {
    std::cout << "Player's Defend List:"<<'\n';
    for(int i=0; i<=numDefend;++i)
        std::cout<<&playerDefendList[i]<<'\n';
    return *playerDefendList;
}

void Player::issueOrders() {


}