//
// Created by bob black on 9/29/2026.
//
#include <random>
#include "DIE.h"

Die::Die() { // default contructor (sets defalt values for it variables)
    m_dieValue = 0;
}

void Die::rollDie() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    m_dieValue = dis(gen);
}

int Die::getDieValue() const {
    // rules for accessing the data
    return m_dieValue;
}