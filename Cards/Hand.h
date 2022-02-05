#ifndef COMP345_P_HAND_H
#define COMP345_P_HAND_H

#include <iostream>
using namespace std;

#include "Card.h"
#include "Deck.h"

class Hand{
public:
    // Constructor that initializes the hand with a specified hand size
    Hand(int handSize);
    // Constructor that initializes the hand with the set size of 12(?)
    Hand( );
    int getHandSize() {return size;}
private:
    int size;

};

#endif //COMP345_P_HAND_H
