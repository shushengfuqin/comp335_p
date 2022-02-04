#include <iostream>
using namespace std;

#include "Card.h"

Card::Card(CardType ct){
    cardType = ct;
}

Card::Card(){
    cardType = rand() % 5;
}

void Card::play(){
    cout << "Played a card of type: " << cardType;
}