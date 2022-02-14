//
// Created by Mia Yan on 9/2/2022.
//
#include <iostream>
#include "Player.h"

using namespace std;

class PlayerDriver{
public:
    PlayerDriver(){};
    ~PlayerDriver(){};
    void callPlayerDriver(){
        //initialize the player
        Player *player=new Player();

        //initialize some new territories.
        Territory *territory1= new Territory( "big", 1 ,1);
        Territory *territory2= new Territory( "small", 2 ,2);
        Territory *territory3= new Territory( "medium", 3 ,3);

        //add territories to the player attack list
        player->attackTerritory(territory1);
        player->attackTerritory(territory2);
        player->attackTerritory(territory3);

        //player attack action
        player->toAttack();

        //instantiate new list for player to defend
        Territory *territory4= new Territory( "large", 4,4 );
        Territory *territory5= new Territory( "ice", 5 ,5);
        Territory *territory6= new Territory( "cap", 6 ,6);

        //add territories to the player defend list
        player->defendTerritory(territory4);
        player->defendTerritory(territory5);
        player->defendTerritory(territory6);

        //player defend actions
        player->toDefend();

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
        player->displayTerritory();


        //create new orders
        Deploy deploy1;
        Advance advance1;
        Bomb bomb1;
        Blockade blockade1;
        Airlift airlift1;
        Negotiate negotiate1;

        //issue new orders
        player->issueOrders(&deploy1);
        player->issueOrders(&advance1);
        player->issueOrders(&bomb1);
        player->issueOrders(&blockade1);
        player->issueOrders(&airlift1);
        player->issueOrders(&negotiate1);


        //create another player using copy constructor
        Player *player2=player;
        player2->toAttack();

        //create another player using assignment operator
        Player *player3;
        player3=player;
        player3->toDefend();

        //use the player stream
        cout<<"player 1 wanna talk: "<<*player<<endl;







    }
};
