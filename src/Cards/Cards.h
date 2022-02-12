#ifndef COMP345_P_CARDS_H
#define COMP345_P_CARDS_H
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
    friend ostream &operator<<(ostream &output, Card &C ) {
        switch (C.cardType)
        {
            case bomb: output << "Bomb"; break;
            case reinforcement: output << "Reinforcement"; break;
            case blockade: output << "Blockade"; break;
            case airlift: output << "AirLift"; break;
            case diplomacy: output << "Diplomacy"; break;
            default: output << "[Unknown cardType]"; break;
        }
        return output;
    }
    Card& operator=(const Card& c)
    {
        this->cardType = c.cardType;
    }
private:
    CardType cardType;
};

class Deck{
public:
    // Constructor that initializes the deck with a specified deck size
    Deck(int deckSize);
    // Constructor that initializes the deck with the set size of 52
    Deck( );
    // Destructor
    ~Deck( );
    void draw(Hand& player);
    void returnToDeck(Card& newCard);
    friend ostream &operator<<( ostream &output, const Deck &D ) {
        for(int i = 0; i < D.size; i++){
            output << D.cards[i];
            if(i < D.size-1)
                output << " --- ";
        }
        return output;
    }
    Deck& operator=(const Deck& d)
    {
        this->front = d.front;
        this->back = d.back;
        this->size = d.size;
        this->cards = new Card[size];

        for(int i = 0; i < d.size; i++){
            this->cards[i] = d.cards[i];
        }
    }
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
    // Constructor that initializes the hand with the set size of 12
    Hand( );
    // Destructor
    ~Hand( );
    void addCard(Card* newCard);
    int getHandSize() {return size;}
    int getHandLimit() {return limit;}
    Card removeCardAtIndex(int index);
    Card* getCardAtIndex(int index){return &cards[index];}
    friend ostream &operator<<( ostream &output, const Hand &H ) {
        for(int i = 0; i < H.size; i++){
            output << H.cards[i];
            if(i < H.size-1)
                output << " --- ";
        }
        return output;
    }
    Hand& operator=(const Hand& h)
    {
        this->limit = h.limit;
        this->size = h.size;
        this->cards = new Card[limit];

        for(int i = 0; i < h.size; i++){
            this->cards[i] = h.cards[i];
        }
    }
private:
    int size;
    int limit;
    Card *cards;
};

#endif //COMP345_P_CARDS_H
