#ifndef COMP345_P_HAND_H
#define COMP345_P_HAND_H

class Hand{
public:
    // Constructor that initializes the hand with a specified hand size
    Hand(int handSize);
    // Constructor that initializes the hand with the set size of 12(?)
    Hand( );
    void draw();
private:
    int size;
    Card cards;
};

#endif //COMP345_P_HAND_H
