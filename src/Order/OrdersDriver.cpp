//
// Created by admin on 2022/2/6.
//

#include <iostream>
#include "Orders.h"

using namespace std;

int main() {


    Player *player1=new Player();
    player1->setPlayerId(1);
    Player* player2 = new Player();
    player2->setPlayerId(2);
    const int SIZE=13;
    Map *map = new Map(SIZE);


    Territory* territory1= new Territory( "big", 1 ,1);
    Territory* territory2= new Territory( "small", 2 ,2);
    Territory* territory3= new Territory( "medium", 3 ,3);
    Territory *territory4= new Territory( "large", 4,4 );

    player1->addTerritory(territory1);
    player1->addTerritory(territory2);
    player2->addTerritory(territory3);
    player2->addTerritory(territory4);

    territory1->setContinentName("North-America");
    territory2->setContinentName("North-America");
    territory3->setContinentName("North-America");
    territory4->setContinentName("North-America");

    territory1->setArmyBonusValue(5);
    territory2->setArmyBonusValue(3);
    territory3->setArmyBonusValue(8);
    territory4->setArmyBonusValue(2);

    map->addTerritory(*territory1, 0);
    map->addTerritory(*territory2, 0);
    map->addTerritory(*territory3, 0);
    map->addTerritory(*territory4, 0);
    // Adjacent Territories
/*    bool adj = map->isAdjacentTerritory(territory1, territory2);
    cout << "Is t1 adjacent to t2: ";
    if (adj) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }*/
/*    void callOrdersDriver() {*/
    //Orders
    cout<<"creating deploy order---------"<<endl;
    Deploy *deploy1 = new Deploy (player1,territory1,3);

    cout<<"validate deploy---------"<<endl;
    deploy1->validate();
    cout<<"execute deploy---------"<<endl;
    deploy1->execute();

    cout<<"creating advance order---------"<<endl;
    Advance* advance1 = new Advance(player1,territory1,territory2,5);

    cout<<"validate advance---------"<<endl;
    advance1->validate();
    cout<<"execute advance---------"<<endl;
    advance1->execute();

    cout<<"creating bomb order---------"<<endl;
    Bomb *bomb1 = new Bomb(player1,territory3);

    cout<<"validate bomb---------"<<endl;
    bomb1->validate();
    cout<<"execute bomb---------"<<endl;
    bomb1->execute();

    cout<<"creating blockade order---------"<<endl;
    Blockade *blockade1 = new Blockade(player1,territory2);

    cout<<"validate blockade---------"<<endl;
    blockade1->validate();
    cout<<"execute blockade---------"<<endl;
    blockade1->execute();


    cout<<"creating airlift order---------"<<endl;
    Airlift *airlift1 = new Airlift(player2,territory3,territory4,3);

    cout<<"validate airlift---------"<<endl;
    airlift1->validate();
    cout<<"execute airlift---------"<<endl;
    airlift1->execute();

    cout<<"creating airlift order---------"<<endl;
    Negotiate *negotiate1 = new Negotiate(player1,player2);

    cout<<"validate negotiate---------"<<endl;
    negotiate1->validate();
    cout<<"execute negotiate--------"<<endl;
    negotiate1->execute();

    /* Advance advance1;
    Bomb bomb1;
    Blockade blockade1;
    Airlift airlift1;
    Negotiate negotiate1;
    //test the valid and execute from orders
   // cout << "\n" << "Here we try to valid and excute the order: deploy1: " << endl;
  deploy1->execute();
    //Orderlist
    Orderslist l1;
    //add orders to the list
    l1.setOrderList(deploy1);
    l1.setOrderList(&advance1);
    l1.setOrderList(&bomb1);
    l1.setOrderList(&blockade1);
    l1.setOrderList(&airlift1);
    l1.setOrderList(&negotiate1);
    //display the orderlist
    cout << "\n" << "Here is the Current Orderlist:" << endl;
    //iterate the entire list
    for (int i = 0; i < l1.getOrderList()->size(); i++) {
        cout << l1.getOrderList()->at(i)->getOrderType() << "\n";
    }
    cout << "\n" << "Now, we try to remove the first element deploy out of the list" << endl;
    //remove an order from the list
    l1.remove(deploy1);
    //display the list
    cout << "\n" << "Here is the Current Orderlist:" << endl;
    for (int i = 0; i < l1.getOrderList()->size(); i++) {
        cout << l1.getOrderList()->at(i)->getOrderType() << "\n";
    }
    cout << "\n" << "Now, we try to move the order at position 1 to position 4" << endl;
    //move and order from 1 to 4
    l1.move(1, 4);
    //display the list
    cout << "\n" << "Here is the Current Orderlist:" << endl;
    for (int i = 0; i < l1.getOrderList()->size(); i++) {
        cout << l1.getOrderList()->at(i)->getOrderType() << "\n";
    }
*//*   }*//*
*/
    return 0;
}