//
// Created by bob black on 11/5/2026.
//
#include <string>

#include "PDGame.h"

#ifndef PIGDICE_PDGAMEV2_H
#define PIGDICE_PDGAMEV2_H


class PDGameV2:public PDGame {
private:
    std::string m_playerName;
public:
    PDGameV2(std::string &playerName);
    //~PDGameV2();
    std::string getPlayerName();
    void playGame() override;
    void displayRules();
};


#endif //PIGDICE_PDGAMEV2_H
