#include <iostream>
using namespace std;

#include "Deck.h"

Deck::Deck(int s){
    size = s;
}

Deck::Deck(){
    size = 52;
}

void Deck::draw() {
    // Player is no longer able to draw a new card
    if(size <= 0){
        cout << "Unable to pick up any more cards. Deck is empty.";
        exit(1);
    }
    // Give hand a card
    size--;
}
