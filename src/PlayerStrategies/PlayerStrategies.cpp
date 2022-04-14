//
// Created by deepbluecanada on 2022-04-08.
//

#include "PlayerStrategies.h"
#include  <random>
#include  <iterator>
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
void Human::issueOrder(Player*& i, Map* generatedMap,bool deployOrNot,vector<Player*> *playerList ) {
    if(deployOrNot){
        if (i->getArmyNum() != 0) {
            bool territoryFalse = false;
            cout << "------------ Player : " << i->getPlayerName() << " ------------" << endl;
            // x the amount of player want to deploy
            int x;
            // y the id for the territory want to deploy army to.
            int y;
            cout << "You have " << i->getArmyNum() << " army left\n";
            cout << "List of territory that you control\n";
            auto territory = i->getTerritoryList();
            i->displayTerritory(territory);
            while(!territoryFalse){
                cout << "Where would you like to deploy for army. Chose by territory Id\n";
                cin >> y;
                for(auto &t : *territory){
                    if(t->getTerritoryId() == y){
                        territoryFalse = true;
                    }
                }
                if(!territoryFalse){
                    cout << "The territory you entered doesn't exit. Please enter again.\n";
                }
            }
            cout << "How many army do you wish to deploy" << endl;
            cin >> x;

            while(x > i->getArmyNum()){
                cout << "You don't have enought amry. Please enter again.\n";
                cin >> x;
            }
            i->removeArmyNum(x);
            for(auto &e : *territory){
                if(e->getTerritoryId() == y){
                    cout << "This is the territory you chose: " << y << endl;
                    auto *deploy = new Deploy(i,e,x);
                    i->getOrderList()->setOrderList(deploy);
                }
            }
            cout << "current army num " << i->getArmyNum() << endl;

        }
    } else {
        string command;
        bool correct = true;
        while (correct){
            cout << "what would you like to do\n";
            cout << "Here is the list of orders\nAdvance\nBomb\nBlockade\nAirlift\nNegotiate\n";
            cin >> command;
            if(command == "Advance"){
                cout << "you chose advance\n";
                // Advance need player, source T, target T, army num
                // All your territory
                int st;
                int tt;
                int armyNum;
                bool issued = false;
                Player *targetPl;
                Territory *sourceTerritory;
                Territory *targetTerritory;
                auto territory = i->getTerritoryList();
                cout << "Your territory\n";
                i->displayTerritory(territory);
//                        for(auto &pT: *territory){
//                            cout << "Territory id: " <<pT->getTerritoryId() <<endl;
//                        }

                //get all adjacent territory of each of your territory
                //get the toAttackList
                auto toAttackTerritory = i->toAttack(generatedMap);

                cout << "All Adjacent territory\n";
                for(auto &pT: *territory){
                    cout << "List of adjacent territory of territory id: " << pT->getTerritoryId() << endl;
                    auto adjacent_territory = generatedMap->getAllAdjacentTerritories(*pT);
                    for(auto &adj: adjacent_territory){
                        // find if this is not part one of his territory
                        if(!i->alreadyOwn(adj)){
                            cout << "Territory Id: " << adj->getTerritoryId() << endl;
                        }
                    }
                }
                while(!issued){
                    cout << "Choose one for your territory. Choose by Id.\n";
                    cin >> st;
                    cout << "Choose one for adjacent territory. Choose by Id.\n";
                    cin >> tt;
                    cout << "How many army would you like to send?\n";
                    cin >> armyNum;

                    // find owner of the target territory
                    // is it controled by a neutral player
//                auto neutralTerritory = neutral->getTerritoryList();
//                for(auto &neutralP: *neutralTerritory){
//                    if(neutralP->getTerritoryId() == tt){
//                        targetPl = neutral;
//                        targetTerritory = neutralP;
//                    }
//                }
                    // if it's controled by a player
                    for(auto &playerlist : *playerList){
                        auto plTerritory = playerlist->getTerritoryList();
                        // go through that player's territory
                        for(auto &plT: *plTerritory){
                            if(plT->getTerritoryId() == tt){
                                targetPl = playerlist;
                                targetTerritory = plT;
                            }
                        }
                    }
                    // find source territory
                    for(auto &pT: *territory){
                        if(pT->getTerritoryId() == st){
                            sourceTerritory = pT;
                            auto *advance = new Advance(i,targetPl,sourceTerritory,targetTerritory,armyNum);
                            i->getOrderList()->setOrderList(advance);
                            issued = true;
                        }
                    }
                    if(!issued){
                        cout << "The id that you entered aren't available please enter again.\n";
                    }
                }
                correct = false;
            } else if (command == "Bomb") {
                cout << "you chose bomb\n";
                bool issued=false;
                // bomb need the player, and the target territory
                // The territory needs to be an adjacent territory
                // list all adjacent territory
                auto playerToAttackList = i->toAttack(generatedMap);

                while(!issued) {
                    for (auto &t: *playerToAttackList) {
                        cout << "Territory Id: " << t->getTerritoryId() << endl;
                    }
                    cout << "Which one would you like to bombard? Choose by ID:\n";
                    int bombId;
                    cin >> bombId;
                    for (auto &t: *playerToAttackList) {
                        if (t->getTerritoryId() == bombId) {
                            Bomb *bomb = new Bomb(i, t);
                            i->getOrderList()->setOrderList(bomb);
                            issued = true;
                        }
                    }
                    if(!issued){
                        cout << "The id that you entered aren't available please enter again.\n";
                    }
                }
                correct = false;
            } else if (command == "Blockade") {
                cout << "you chose blockade\n";
                bool issued = false;
                // list all territory user control.
                auto territory = i->getTerritoryList();
                //target territory;
                int t;
                for(auto &pTerritory : *territory){
                    cout << "Territory ID: " << pTerritory->getTerritoryId() << " Territory Name : " << pTerritory->getName() << endl;
                }
                while(!issued) {
                    cout << "Which territory would you like to use Blockade. Chose by id\n";
                    cin >> t;
                    for (auto &e: *territory) {
                        if (e->getTerritoryId() == t) {
                            cout << "This is the territory you chose: " << t << endl;
                            auto *blockade = new Blockade(i, e);
                            i->getOrderList()->setOrderList(blockade);
                            issued = true;
                            break;
                        }
                    }
                    if(!issued){
                        cout << "The id that you entered aren't available please enter again.\n";
                    }
                }
                correct = false;
            } else if (command == "Airlift") {
                cout << "you chose airlift\n";
                int sourceT;
                int targetT;
                int armyNum;
                Territory *sourceTerritory;
                Territory *targetTerritory;
                bool issued = false;
                //Airlift need player, fromT, toT, army num
                //get list of controlled territory and other territory;
                auto territory = i->getTerritoryList();
                while(!issued) {
                    cout << "Your territory by Id.\n";
                    for(auto &t: *territory){
                        cout << "Territory Id: " << t->getTerritoryId() << endl;
                    }
                    cout << "Chose one of your territory\n";
                    cin >> sourceT;
                    //get all other territory
                    for(auto &t: *territory){
                        if(t->getTerritoryId() != sourceT){
                            cout << "Territory Id: " << t->getTerritoryId() << endl;
                        }
                    }
                    cout << "Chose one of the your other's territory\n";
                    cin >> targetT;
                    // find source territory
                    for (auto &pTerritory: *territory) {
                        if (pTerritory->getTerritoryId() == sourceT) {
                            sourceTerritory = pTerritory;
                        }
                    }

                    // find target territory
                    for (auto &pTerritory: *territory) {
                        if (pTerritory->getTerritoryId() == targetT) {
                            targetTerritory = pTerritory;
                            cout << "How many army would you like to send?\n";
                            cin >> armyNum;
                            // create Airlift obj
                            auto *airlift = new Airlift(i, sourceTerritory, targetTerritory, armyNum);
                            i->getOrderList()->setOrderList(airlift);
                            issued = true;
                        }
                    }
                    if(!issued){
                        cout << "The id that you entered aren't available please enter again.\n";
                    }
                }
                correct = false;
            } else if (command == "Negotiate") {
                bool issued = false;
                cout << "you chose negotiate\n";
                //print all other player
                cout << "Please chose your target player by id\n";
                for(auto &j: *playerList){
                    if(i != j){
                        cout << "Player Id : " << j->getPlayerId() << ". Player Name : "<< j->getPlayerName()<<endl;
                    }
                }
                int target;
                while(!issued) {
                    cin >> target;
                    cout << "You chose Player: " << target << endl;
                    for (auto &y: *playerList) {
                        if (y->getPlayerId() == target) {
                            cout << "this is the player's id that you choose " << y->getPlayerId() << endl;
                            auto *negotiate = new Negotiate(i, y);
                            i->getOrderList()->setOrderList(negotiate);
                            issued = true;
                        }
                    }
                    if(!issued){
                        cout << "The id that you entered aren't available please enter again.\n";
                    }
                }
                correct = false;
            } else {
                cout << "please enter an available order\n";
                continue;
            }
        }
    }
}


//vector<Territory *>* Human::toDefend(Map* Map, Player &player) {
//    cout << "Human to defend" << endl;
//    return {};
//}
//vector<Territory *>* Human::toAttack() {
//    return p->getAttackList();
//}

//Random an object from a list

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}


/**
 * Player Strat Aggressive
 */

//Default Constructor
Aggressive::Aggressive(): PlayerStrategy() {
    setStrategyName("Aggressive");
}

// it will only issue deploy and advance to attack enemy territory
void Aggressive::issueOrder(Player*& i, Map* generatedMap, bool deployOrNot, vector<Player*> *playerList ) {
    if(deployOrNot){
        if (i->getArmyNum() != 0) {
            bool territoryFalse = false;
            cout << "------------ Player : " << i->getPlayerName() << " ------------" << endl;
            // x the amount of player want to deploy
            int x;
            // y the id for the territory want to deploy army to.
            int y;
            cout << "You have " << i->getArmyNum() << " army left\n";
            cout << "List of territory that you control\n";
            auto territory = i->getTerritoryList();
            i->displayTerritory(territory);

            cout << "Where would you like to deploy for army. Chose by territory Id\n";
           //TODO:  how to get the number of turns , if the first turn, then random pick a territory, if not then deploy to the strongest
            if(true){ //count = 0
                Territory *randT = *select_randomly(i->getTerritoryList()->begin(),i->getTerritoryList()->end());
                y = randT->getTerritoryId();
            }
            else{
                y = i->findStrongestCountry()->getTerritoryId();
            }
            cout <<y<<"\n";
                //cin >> y;

            cout << "How many army do you wish to deploy" << endl;
            srand((unsigned int)time(NULL));
            x = rand()% i->getArmyNum()+1;
            cout << x<<"\n";
            //cin >> x;
            while(x > i->getArmyNum()){
                cout << "You don't have enought amry. Please enter again.\n";
                cin >> x;
            }
            i->removeArmyNum(x);
            for(auto &e : *territory){
                if(e->getTerritoryId() == y){
                    cout << "This is the territory you chose: " << y << endl;
                    auto *deploy = new Deploy(i,e,x);
                    i->getOrderList()->setOrderList(deploy);
                }
            }
            cout << "current army num " << i->getArmyNum() << endl;

        }
    } else {
        string command;
        bool correct = true;
        while (correct){
            cout << "what would you like to do\n";
            cout << "Here is the list of orders\nAdvance\nBomb\nBlockade\nAirlift\nNegotiate\n";
            //If not Deploy,The aggressive player will only advance armies to the strongest country

                cout << "you chose advance\n";
                // Advance need player, source T, target T, army num
                // All your territory
                int st;
                int tt;
                int armyNum;
                bool issued = false;
                //TODO: random a target player from playerlist
                Player *targetPl;
                Territory *sourceTerritory;
                Territory *targetTerritory;

                auto territory = i->getTerritoryList();
                cout << "Your territory\n";
                i->displayTerritory(territory);


                //get all adjacent territory of each of your territory
                //get the toAttackList
                auto toAttackTerritory = i->toAttack(generatedMap);

                cout << "All Adjacent territory\n";
                for(auto &pT: *territory){
                    cout << "List of adjacent territory of territory id: " << pT->getTerritoryId() << endl;
                    auto adjacent_territory = generatedMap->getAllAdjacentTerritories(*pT);
                    for(auto &adj: adjacent_territory){
                        // find if this is not part one of his territory
                        if(!i->alreadyOwn(adj)){
                            cout << "Territory Id: " << adj->getTerritoryId() << endl;
                        }
                    }
                }


                while(!issued){
                    cout << "Choose one for your territory. Choose by Id.\n";
                    //cin >> st;
                    sourceTerritory = i->findStrongestCountry();
                    st = sourceTerritory->getTerritoryId();
                    cout<<st<<endl;

                    cout << "Choose one for adjacent territory. Choose by Id.\n";
                    //cin >> tt;
                    //Todo: This doesnt work!!!


                    vector<Territory*> adjacentForSource;
                    for(auto &pT: *territory){
                        cout << "List of adjacent territory of territory id: " << pT->getTerritoryId() << endl;
                        auto adjacent_territory = generatedMap->getAllAdjacentTerritories(*pT);
                        for(auto &adj: adjacent_territory){
                            // find if this is not part one of his territory
                            if(!i->alreadyOwn(adj)){
                                cout << "Territory Id: " << adj->getTerritoryId() << endl;
                                adjacentForSource.push_back(adj);
                            }
                        }
                    }
//                    for(auto &pT: *territory){
//                        if(pT->getTerritoryId() == st){
//                            sourceTerritory = pT;
//                            auto adjacent_territory = generatedMap->getAllAdjacentTerritories(*pT);
//                            for(auto &adj: adjacent_territory){
//                                // find if this is not part one of his territory
//                                if(!i->alreadyOwn(adj)){
//                                    cout << "Territory Id: " << adj->getTerritoryId() << endl;
//                                    adjacentForSource->push_back(adj);
//                                }
//                            }
//                        }
//                    }


                    targetTerritory = *select_randomly(adjacentForSource.begin(),adjacentForSource.end());
                    cout <<targetTerritory->getTerritoryId()<<endl;

                    cout << "How many army would you like to send?\n";
                    //cin >> armyNum;
                    armyNum = rand()%sourceTerritory->getNumArmies()+1;

                    // if it's controled by a player
                    for(auto &playerlist : *playerList){
                        auto plTerritory = playerlist->getTerritoryList();
                        // go through that player's territory
                        for(auto &plT: *plTerritory){
                            if(plT->getTerritoryId() == tt){
                                targetPl = playerlist;
                                targetTerritory = plT;
                            }
                        }
                    }
                    // find source territory
                    for(auto &pT: *territory){
                        if(pT->getTerritoryId() == st){
                            sourceTerritory = pT;
                            auto *advance = new Advance(i,targetPl,sourceTerritory,targetTerritory,armyNum);
                            i->getOrderList()->setOrderList(advance);
                            issued = true;
                        }
                    }
                    if(!issued){
                        cout << "The id that you entered aren't available please enter again.\n";
                    }
                }
                correct = false;
        }
    }
}

//vector<Territory *> Aggressive::toAttack(Map* Map, Player &player) {
//    cout << "Aggressive to attack" << endl;
//    return {};
//}
//
//vector<Territory *> Aggressive::toDefend(Map* Map, Player &player) {
//    cout << "Aggressive to defend" << endl;
//    return {};
//}

/**
*  Player Strat Benevolent
*/

//Default Constructor
Benevolent::Benevolent(): PlayerStrategy() {
    setStrategyName("Benevolent");
}

// It will only issue deploy and advance to own territory
void Benevolent::issueOrder(Player*& i, Map* generatedMap,bool deployOrNot,vector<Player*> *playerList) {

}

//vector<Territory *> Benevolent::toAttack(Map* Map, Player &player) {
//    cout << "Benevolent to attack" <<endl;
//    return {};
//}
//
//vector<Territory *> Benevolent::toDefend(Map* Map, Player &player) {
//    cout << "Benevolent to defend" <<endl;
//    return {};
//}

/**
*  Player Strat Neutral
*/

//Default Constructor
Neutral::Neutral(): PlayerStrategy() {
    setStrategyName("Neutral");
}


// Does not thing
void Neutral::issueOrder(Player*& i, Map* generatedMap,bool deployOrNot,vector<Player*> *playerList) {

}

//vector<Territory *> Neutral::toAttack(Map* Map, Player &player) {
//    cout << "Neutral to attack" << endl;
//    return {};
//}
//
//vector<Territory *> Neutral::toDefend(Map* Map, Player &player) {
//    cout << "Neutral to defend" << endl;
//    return {};
//}

/**
*  Player Strat Cheater
*/

//Default Constructor
Cheater::Cheater(): PlayerStrategy() {
    setStrategyName("Cheater");
}

// special issueOrder. add a cheat order for him which will get all his adjacent territory and change the territory to the cheaters
void Cheater::issueOrder(Player*& i, Map* generatedMap,bool deployOrNot,vector<Player*> *playerList) {

}

//vector<Territory *> Cheater::toAttack(Map* Map, Player &player) {
//    cout << "Cheater to attack" << endl;
//    return {};
//}
//
//vector<Territory *> Cheater::toDefend(Map* Map, Player &player) {
//    cout << "Cheater to defend" << endl;
//    return {};
//}


