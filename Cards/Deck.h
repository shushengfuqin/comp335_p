#ifndef COMP345_P_DECK_H
#define COMP345_P_DECK_H

#include <iostream>
using namespace std;

#include "Card.cpp"
#include "Hand.h"

class Deck{
public:
    // Constructor that initializes the deck with a specified deck size
    Deck(int deckSize);
    // Constructor that initializes the deck with the set size of 52(?)
    Deck( );
    void draw(Hand player);
    void deleteDeck();
private:
    int size;
    Card *cards;
};

#endif //COMP345_P_DECK_H
