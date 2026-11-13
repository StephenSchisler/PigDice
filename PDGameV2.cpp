//
// Created by bob black on 11/5/2026.
//
#include <string>
#include <iostream>

#include "PDGame.h"
#include "PDGameV2.h"

int index = 1; // I know global variables are not ideal, but this being inside of the PDGameV2 constructor kept resetting what number the index was at, so this was the only other thing I could think.

PDGameV2::PDGameV2(std::string &playerName) {

    if (!playerName.empty()) {
        m_playerName = playerName;
    }
    else {
        m_playerName = "Anonymous Player " + std::to_string(index);
        index = index + 1;
    }
}

//~PDGameV2() {}

std::string PDGameV2::getPlayerName() {
    return m_playerName;
}

void PDGameV2::playGame(){
    m_myTurn.takeTurn();
    m_gameScore += m_myTurn.getScoreThisTurn();
    if (m_gameScore < 50) {
        m_myTurn.resetTurnOver();
        m_myTurn.resetScoreThisTurn();
    }
}

void PDGameV2::displayRules() {
    std::cout << "\nLet's Play PIG Dice!\n" << std::endl;
    std::cout << "* See which player will reach 50 points in the fewest turns." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1." << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you save all points for the turn";
}