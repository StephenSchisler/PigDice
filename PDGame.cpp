//
// Created by bob black on 10/6/2026.
//
#include <iostream>
#include "PDGame.h"

PDGame::PDGame() { // this has to call/invoke the other 2 functions in this file, since only this function is public in PDGame
    m_gameOver = false;
    m_gameScore = 0;

    m_myTurn.setParentGame(this); // 7. (also, this spesific spot matters. also also, this is a new key word, which is a pointer to itself)

    displayRules();
    playGame();
}

int PDGame::getGameScore() { // 2.
    return m_gameScore;
}

void PDGame::displayRules() {
    std::cout << "Let's Play PIG Dice!\n" << std::endl;
    std::cout << "* See how many turns it takes you to get to 20 points." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1." << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you bank all points for the turn to the game score\n" << std::endl;
}

void PDGame::playGame() {
    while (!m_gameOver){
        m_myTurn.takeTurn(); // 1st,  take your the turn
        m_gameScore += m_myTurn.getScoreThisTurn(); // alter values to mach the turns result
        if (m_gameScore >= 20) { // check if the goal score has been reached
            m_gameOver = true;
        }
        else {
            m_myTurn.resetTurnOver(); //come back to this lower one later
            m_myTurn.resetScoreThisTurn();
        }
    }
    std::cout << "You finished wih a final score of " << m_gameScore << " in " << m_myTurn.getTurnCount() << " turns!" << std::endl;
    std::cout << "Thanks for playing PIG Dice!" << std::endl;

}
