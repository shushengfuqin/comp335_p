#ifndef COMP345_P_DECK_H
#define COMP345_P_DECK_H

#include <iostream>
using namespace std;

class Deck{
public:
    // Constructor that initializes the deck with a specified deck size
    Deck(int deckSize);
    // Constructor that initializes the deck with the set size of 52(?)
    Deck( );
    void draw();
private:
    int size;
    Card cards;
};

#endif //COMP345_P_DECK_H
