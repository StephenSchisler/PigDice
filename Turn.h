#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H
#include "DIE.h"

class PDGame; // 3.

class Turn {
private:
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
    PDGame* m_parentGame = nullptr; // 4.
public:
    Turn();
    //Turn(&);
    void setParentGame(PDGame* parentGame); // 5.
    //Turn(&);
    void takeTurn();
    int getScoreThisTurn();
    void resetTurnOver();
    int getTurnCount();
    void resetScoreThisTurn();
private:
    void roll(); // can only be acceses by functions in the object (aka in this case all of the functions directly above this one)
};


#endif //PIGDICE_TURN_H
