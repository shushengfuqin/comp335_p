#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#include "Cards.h"

int main( ){
    srand(time(NULL));
    Deck deckA(10);
    //deckA.deleteDeck();
    cout << "~!" << endl << endl;
    Hand playerA(15);

    cout << "Hello, World!" << std::endl;

    // Draw cards from deck
    for(int i = 0; i < 15; i++){
        deckA.draw(playerA);
    }

    // Play cards from hand
    for(int i = 0; i < playerA.getHandSize(); i++){
        Card* chosen = playerA.getCardAtIndex(3);
        chosen->play(3, playerA, deckA);
    }

    // Draw cards from deck (again)
    for(int i = 0; i < 3; i++){
        deckA.draw(playerA);
    }

    // Clear deck
    deckA.deleteDeck();

    return 0;
}
