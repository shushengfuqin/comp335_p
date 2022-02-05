#include <iostream>
using namespace std;

#include "Card.h"
#include "Hand.h"

Card::Card(CardType ct){
    cardType = ct;
}

Card::Card(){
    //cardType = rand() % 5;
}

void Card::play(Hand player){
    cout << "Played a card of type: " << cardType;
    // Remove from hand
    // Return card to deck
}