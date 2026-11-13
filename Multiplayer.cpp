//
// Created by bob black on 11/5/2026.
//

#include "Multiplayer.h"

Multiplayer::Multiplayer() {
    m_mpGameOver = false;
    std::string tempName;


    int count = 0;
    std::cout << "How many people are playing? ";
    std::cin >> count;
    std::cin.ignore(100, '\n');
    for (int i = 0; i < count; i++) {
        std::cout << "Enter player " << i + 1 << "'s name: ";
        std::getline(std::cin, tempName);
        m_players.emplace_back(tempName); // dynamicly instatiates
    }

    mpPlayGame();
}

void Multiplayer::mpPlayGame() {
    m_players[0].displayRules();

    while (!m_mpGameOver) {
        for (int i = 0; i < m_players.size(); i++) {
            std::cout << "\n\n" << m_players[i].getPlayerName();
            m_players.at(i).playGame();
            displayScoreBoard();
        }
        checkForWinner();
    }
}

void Multiplayer::checkForWinner() {
    std::string winName;
    winName = "blank";

    int winID = 0;

    int numOfGoalsReached = 0;

    for (int i = 0; i < m_players.size(); i++) {
        if (m_players[i].getGameScore() >= 50) { // check if the goal score has been reached
            winName = m_players[i].getPlayerName() ;
            winID = i;
            m_mpGameOver = true;

            std::cout << "\nCongratulations "<< winName << " you win with a score of " << m_players[winID].getGameScore() << std::endl;
        }
    }
}

void Multiplayer::displayScoreBoard() {
    for (int i = 0; i < m_players.size(); i++) {
        std:: cout << m_players[i].getPlayerName()<< " (Score:" << m_players[i].getGameScore() << ") | ";
    }
    std::cout << std::endl;

}