#include <iostream>
using namespace std;

#include "Deck.h"
#include "card.h"
#include "hand.h"

Deck::Deck(int s){
    size = s;
    cards = new Card[size];
}

Deck::Deck(){
    size = 52;
    cards = new Card[size];
}

void Deck::draw(Hand player) {
    // Player is no longer able to draw a new card
    if(size <= 0) {
        cout << "Unable to pick up any more cards. Deck is empty.";
        exit(1);
    }

    // Player's hand is full and they cannot pick up another card

    // Give hand a card
    size--;
}

void Deck::deleteDeck() {
    delete [] cards;
}
