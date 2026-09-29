//
// Created by bob black on 9/29/2026.
//

#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

class Die {
private:
    int m_value;
    int m_numbOfSides;
public:
    Die();
    void setNumbOfSides(int numbOfSides);
    int getNumbOfSides();
    void set_value();
    int get_value();
};

#endif //PIGDICE_DIE_H
