//
// Created by bob black on 9/29/2026.
//
#include <random>
#include "DIE.h"

Die::Die() { // default contructor (sets defalt values for it variables)
    m_numbOfSides = 6;
    set_value();
}

void Die::setNumbOfSides(int numbOfSides) {
    switch (numbOfSides) {
        case 4:
            m_numbOfSides = 4;
            break;
        case 6:
            m_numbOfSides = 6;
            break;
        case 8:
            m_numbOfSides = 8;
            break;
            defalut:
                m_numbOfSides = 6;
            break;
    }
    m_numbOfSides = numbOfSides;
}

int Die::getNumbOfSides() {
    return m_numbOfSides;
}

void Die::set_value() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, m_numbOfSides);
    m_value = dis(gen);
}

int Die::get_value() {
    // rules for accessing the data
    return m_value;
}