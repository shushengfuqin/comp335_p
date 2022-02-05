#ifndef COMP345_P_CARD_H
#define COMP345_P_CARD_H

#include <iostream>
using namespace std;

#include "Hand.h"

enum CardType { bomb, reinforcement, blockade, airlift, diplomacy };

class Card{
public:
    // Constructor that initializes the card as the specified card type
    Card(CardType ct);
    // Constructor that initializes the card to a random card type
    Card( );
    void play(Hand player);
private:
    CardType cardType;
};

#endif //COMP345_P_CARD_H
