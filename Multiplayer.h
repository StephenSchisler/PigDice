//
// Created by bob black on 11/5/2026.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "PDGameV2.h"


#ifndef PIGDICE_MULTIPLAYER_H
#define PIGDICE_MULTIPLAYER_H


class Multiplayer {
private:
    std::vector<PDGameV2> m_players;
    bool m_mpGameOver;
public:
    Multiplayer ();
    void mpPlayGame();
private:
    void checkForWinner();
    void displayScoreBoard();
};


#endif //PIGDICE_MULTIPLAYER_H
