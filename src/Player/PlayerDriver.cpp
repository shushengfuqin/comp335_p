//
// Created by Mia Yan on 9/2/2022.
//
#include <iostream>
#include "Player.h"

using namespace std;

class PlayerDriver{
public:
    PlayerDriver()= default;;
    ~PlayerDriver()= default;;
    void callPlayerDriver(){
        //initialize the player
        Player *player=new Player();
        player->setPlayerId(1);

        //initialize some new territories.
        Territory *territory1= new Territory( "big", 1 ,1);
        Territory *territory2= new Territory( "small", 2 ,2);
        Territory *territory3= new Territory( "medium", 3 ,3);

        //add territories to the player attack list
        player->attackTerritory(territory1);
        player->attackTerritory(territory2);
        player->attackTerritory(territory2);
        player->attackTerritory(territory3);

        //player attack action
        player->toAttack();
        player->displayTerritory(player->getAttackList());

        //instantiate new list for player to defend
        Territory *territory4= new Territory( "large", 4,4 );
        Territory *territory5= new Territory( "ice", 5 ,5);
        Territory *territory6= new Territory( "cap", 6 ,6);

        //add territories to the player defend list
        player->defendTerritory(territory4);
        player->defendTerritory(territory5);
        player->defendTerritory(territory5);
        player->defendTerritory(territory6);

        //player defend actions
        player->toDefend();
        player->displayTerritory(player->getDefendList());

        //verify player has hand by adding cards
        player->getHandLimit();


        //create new territory that should be used to add into the player class
        Territory *territory7= new Territory( "pikachu", 7,7 );
        Territory *territory8= new Territory( "eevee", 8 , 8);
        Territory *territory9= new Territory( "jigglypuff", 9, 9 );


        //add territory belongs to the player
        player->addTerritory(territory7);
        player->addTerritory(territory8);
        player->addTerritory(territory9);
        player->displayTerritory(player->getTerritoryList());



        //create new orders
        Deploy deploy1;
        Advance advance1;
        Bomb bomb1;
        Blockade blockade1;
        Airlift airlift1;
        Negotiate negotiate1;

        //issue new orders
/*
        player->issueOrders(&deploy1);
        player->issueOrders(&advance1);
        player->issueOrders(&bomb1);
        player->issueOrders(&blockade1);
        player->issueOrders(&airlift1);
        player->issueOrders(&negotiate1);
*/


        //create another player using copy constructor
//        Player *player2=player;
//        player2->setPlayerId(2);
//        player2->toAttack();

        //create another player using assignment operator
//        Player *player3;
//        player3=player;
//        player3->setPlayerId(3);
//        player3->toDefend();

        //use the player stream
        cout<<"player 1 wanna talk: "<<*player<<endl;

        cout<<"here is the new test"<<endl;
        player->removeTerritory(territory7);
        player->displayTerritory(player->getTerritoryList());

        player->cancelAttack(territory1);
        player->cancelAttack(territory1);
        player->displayTerritory(player->getAttackList());

        player->cancelDefend(territory4);
        player->cancelDefend(territory4);
        player->displayTerritory(player->getDefendList());


        //create a new player
        Player *player4=new Player();
        player4->setPlayerId(4);
        //create new territory that should be used to add into the player class
        Territory *territory10= new Territory( "new territory 10", 10,7 );
        Territory *territory11= new Territory( "new territory 11", 11 , 8);
        Territory *territory12= new Territory( "new territory 12", 12, 9 );


        //add territory belongs to the player
        player4->addTerritory(territory10);
        player4->addTerritory(territory11);
        player4->addTerritory(territory12);
        player4->displayTerritory(player4->getTerritoryList());

        player->switchTerritories(territory8, player,player4);
        player->displayTerritory(player->getTerritoryList());
        player4->displayTerritory(player4->getTerritoryList());


        cout<<player->getPlayerNumOfTerritoriesInContinent(9)<<endl;



        player->displayTerritory(player->getTerritoryList());
        player->containsTerritory(territory1);
        player->containsTerritory(territory2);
        player->containsTerritory(territory9);

        territory1->setPlayer(1);
        cout<<territory1->getPlayer()<<endl;
        territory1->neutralState();
        cout<<territory1->getPlayer()<<endl;
    }
};
