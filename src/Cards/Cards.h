#ifndef CARDTEST_CARDS_H
#define CARDTEST_CARDS_H
#pragma once
#include <iostream>
using namespace std;

enum CardType { bomb = 1, reinforcement = 2, blockade = 3, airlift = 4, diplomacy = 5 };

class Card;
class Deck;
class Hand;

class Card{
public:
    // Constructor that initializes the card as the specified card type
    Card(CardType ct);
    // Constructor that initializes the card to a random card type
    Card( );
    void play(int index, Hand& player, Deck& deck);
    int asNumber(){return cardType;}
    inline const char* toString()
    {
        switch (cardType)
        {
            case bomb:   return "Bomb";
            case reinforcement:   return "Reinforcement";
            case blockade: return "Blockade";
            case airlift:   return "AirLift";
            case diplomacy: return "Diplomacy";
            default:      return "[Unknown cardType]";
        }
    }
private:
    CardType cardType;
};

class Deck{
public:
    // Constructor that initializes the deck with a specified deck size
    Deck(int deckSize);
    // Constructor that initializes the deck with the set size of 52(?)
    Deck( );
    void draw(Hand& player);
    void returnToDeck(Card& newCard);
    void deleteDeck();
private:
    int size;
    int front;
    int back;
    Card *cards;
};

class Hand{
public:
    // Constructor that initializes the hand with a specified hand size
    Hand(int handSize);
    // Constructor that initializes the hand with the set size of 12(?)
    Hand( );
    void addCard(Card* newCard);
    int getHandSize() {return size;}
    int getHandLimit() {return limit;}
    Card removeCardAtIndex(int index);
    Card* getCardAtIndex(int index){return &cards[index];}
    void outputCards() {
        for(int i = 0; i < size; i++){
            cout << cards[i].toString() << " -- ";
        }
        cout << endl;
    };
    void deleteHand();
private:
    int size;
    int limit;
    Card *cards;
};

#endif //CARDTEST_CARDS_H
