#include <iostream>
using namespace std;

#include "Card.h"
#include "Hand.h"

Hand::Hand(int s){
    size = s;
    cards = new Card[size];
}

Hand::Hand(){
    size = 52;
    cards = new Card[size];
}

