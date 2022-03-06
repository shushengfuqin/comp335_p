//
// Created by admin on 2022/2/6.
//

#include <iostream>
#include "Orders.h"
#include "../Map/Map.h"

using namespace std;

class OrdersDriver {

public:
    OrdersDriver(){};
    ~OrdersDriver(){};

    void callOrdersDriver() {

         // creation of map object
         const int SIZE = 13;
        Map *map = new Map(SIZE); // new map

         Player *player1=new Player();
         player1->setPlayerId(1);
         Player* player2 = new Player();
         player2->setPlayerId(2);

         Territory* territory1= new Territory( "big", 1 ,1);
         Territory* territory2= new Territory( "small", 2 ,2);
         Territory* territory3= new Territory( "medium", 3 ,3);
         player1->addTerritory(territory1);
         player1->addTerritory(territory2);
         player2->addTerritory(territory3);


         territory1->setArmyBonusValue(5);
         territory2->setArmyBonusValue(3);
         territory3->setArmyBonusValue(8);

/*    void callOrdersDriver() {*/
        //Orders
        LogObserver* logObserver = new LogObserver();
        cout<<"creating deploy order"<<endl;
        Deploy *deploy1 = new Deploy (player1,territory1,3);
        cout<<"validate deploy"<<endl;
        deploy1->Attach(logObserver);
        deploy1->validate();
        deploy1->execute();

        Advance* advance1 = new Advance(player1,territory1,territory2,5);
        advance1->Attach(logObserver);
        advance1->validate();

       /* Advance advance1;
        Bomb bomb1;
        Blockade blockade1;
        Airlift airlift1;
        Negotiate negotiate1;
        deploy1.Attach(logObserver);
        advance1.Attach(logObserver);
        bomb1.Attach(logObserver);
        blockade1.Attach(logObserver);
        airlift1.Attach(logObserver);
        negotiate1.Attach(logObserver);
        Negotiate negotiate1;

        //test the valid and execute from orders
       // cout << "\n" << "Here we try to valid and excute the order: deploy1: " << endl;

      deploy1->execute();
        cout << "\n" << "Here we try to valid and excute the order: deploy1: " << endl;
        deploy1.validate();
        deploy1.execute();

        //Orderlist
        Orderslist l1;

        //add orders to the list
        l1.setOrderList(&deploy1);
        l1.setOrderList(&advance1);
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
        l1.remove(&deploy1);


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

        deploy1.Detach(logObserver);
        advance1.Detach(logObserver);
        bomb1.Detach(logObserver);
        blockade1.Detach(logObserver);
        airlift1.Detach(logObserver);
        negotiate1.Detach(logObserver);
    }

};
        }
 *//*   }*//*
*/
}};