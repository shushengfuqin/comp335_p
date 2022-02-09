//
// Created by Mia Yan on 8/2/2022.
//

#include "Player.h"

Player::Player(){
    playerHand=new Hand();
    playerTerritoryList ;
    playerDefendList;
    playerAttackList;


}

void Player::attackTerritory(Territory *territory){
    playerAttackList.push_back(*territory);
}
void Player::defendTerritory(Territory *territory){
    playerDefendList.push_back(*territory);
}
vector<Territory> Player::toAttack() {
    std::cout << "Player's Attack List:"<<'\n';
    for(int i=0; i<playerAttackList.size();++i)
        cout<<playerAttackList[i].getName()<<'\n';
    return playerAttackList;

}

vector<Territory> Player::toDefend() {
    std::cout << "Player's Defend List:"<<'\n';
    for(int i=0; i<playerDefendList.size();++i)
        std::cout<<playerDefendList[i].getName()<<'\n';
    return playerDefendList;
}

void Player::issueOrders() {


}