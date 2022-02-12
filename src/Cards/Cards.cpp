#include "Cards.h"

Card::Card(CardType ct){
    cardType = ct;
}

Card::Card(){
    int val = rand() % 5 + 1;

    switch(val){
        case 1: cardType = CardType::bomb; break;
        case 2: cardType = CardType::reinforcement; break;
        case 3: cardType = CardType::blockade; break;
        case 4: cardType = CardType::airlift; break;
        case 5: cardType = CardType::diplomacy; break;
    }
}

void Card::play(int index, Hand &player, Deck &deck) {
    // Take played card
    Card usedCard;
    cout << "HAND: " << player << endl;
    usedCard = player.removeCardAtIndex(index);    // Remove from hand and shift
    cout << "Played a card of type: " << usedCard << endl;
    cout << "HAND: " << player << endl;

    // Return card to deck
    deck.returnToDeck(usedCard);
}

///////

Deck::Deck(int s){
    size = s;
    cards = new Card[size];
    front = 0;
    back = s-1;
}

Deck::Deck(){
    size = 52;
    cards = new Card[size];
    front = 0;
    back = 51;
}

Deck::~Deck() {
    delete [] cards;
    cards = nullptr;
}


void Deck::draw(Hand& player) {
    // Player is no longer able to draw a new card
    if(size <= 0) {
        cout << "Unable to pick up any more cards. Deck is empty." << endl;
        return;
    }

    // Player's hand is full and they cannot pick up another card
    if(player.getHandSize() >= player.getHandLimit()){
        cout << "Unable to pick up any more cards. Player's hand is full." << endl;
        return;
    }

    // Take top card
    Card* topCard;
    topCard = &cards[front];
    if(front >= back){      //only one element in queue
        front = -1;
        back = -1;
    }
    else {
        front++;
    }
    cout << "Drawing a card => " << *topCard << " from Deck" << endl;

    // Give hand the card
    player.addCard(topCard);
    size--;
}

void Deck::returnToDeck(Card &newCard) {
    // Was the deck just empty?
    if(front == -1)
        front = 0;

    back++;
    cards[back] = newCard;
    size++;
    cout << endl << "Adding a card => " << cards[back] << " back to Deck" << endl << endl;
}

///////

Hand::Hand(int s){
    limit = s;
    size = 0;
    cards = new Card[limit];
}

Hand::Hand(){
    limit = 12;
    size = 0;
    cards = new Card[limit];
}

Hand::~Hand() {
    delete [] cards;
    cards = nullptr;
}

void Hand::addCard(Card* newCard){
    cards[size] = *newCard;
    size++;
}

Card Hand::removeCardAtIndex(int index) {
    Card removed = cards[index];

    for(int i = index; i < size-1; i++){
        cards[i] = cards[i+1];
    }

    cout << "Removed -> " << removed << endl;
    size--;
    return removed;
}
