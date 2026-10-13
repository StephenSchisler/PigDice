//
// Created by bob black on 10/6/2026.
//
#include <iostream> // global level library (in ideal conditions, this code is placed above the local level librarys)
#include "Turn.h" // note: this is called a local level library
#include "PDGame.h" // 8.

Turn::Turn() { // defalt constructor: will set default values for variables
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = '\0'; // \0 is called the Null Character (it represents that a character is explisitly nothinng)
}

void Turn::setParentGame(PDGame* parentGame) { // 6.
    m_parentGame = parentGame;
}

void Turn::takeTurn() {
    m_turnCount++; // means the same thing as mg.turn_count = mg.turn_count + 1
    std::cout << "TURN " << m_turnCount;
    std::cout << " - Game Score: " << m_parentGame->getGameScore(); // 9. note: when you need to invoke a POINTER to an object rather than an object itself, use an arow "<-" insted of a dot "."
    //PAST ISSUE: the "part" Turn object needs access to m_gameScore from the "whole", PDGame. Check nubered commented code peaces for steps.
    while (!m_turnOver) {
        std::cout << "\nroll or hold? (r/h): " ;//<< std::endl;
        std::cin >> m_choice;
        if (m_choice == 'r') {
            roll();
        }
        else if (m_choice == 'h') {
            m_turnOver = true;
        }
        else {
            std::cout << "Invalid choice!";
        }

    }
    std::cout << "Score Banked This Turn: " << m_scoreThisTurn << "\n" << std::endl;

}

int Turn::getScoreThisTurn() {
    return m_scoreThisTurn;
}

void Turn::resetTurnOver() { // reminder: voids don't return anything
    m_turnOver = false;
}

int Turn::getTurnCount() {
    return m_turnCount;
}

void Turn::resetScoreThisTurn() {
    m_scoreThisTurn = 0;
}

void Turn::roll() { // Reminder: this one is private
    m_myDie.rollDie(); // calling the public function to roll the die
    std::cout << "Die: " << m_myDie.getDieValue();
    if (m_myDie.getDieValue() == 1) {
        std::cout << "\nTurn over. No score.\n" ;
        m_scoreThisTurn = 0;
        m_turnOver = true;
    }
    else {
        m_scoreThisTurn += m_myDie.getDieValue();
        std::cout << " - Running score this turn: " << m_scoreThisTurn;
    }
}
