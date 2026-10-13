//
// Created by bob black on 9/29/2026.
//

#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

class Die {
private:
    int m_dieValue;
public:
    Die();
    void rollDie();
    int getDieValue() const;
};

#endif //PIGDICE_DIE_H
