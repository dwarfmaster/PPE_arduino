
#include "dir.hpp"

Dir::Dir()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    for(int i = 2; i < 6; ++i)
        digitalWrite(i, LOW);
    m_st = 0;
}

void Dir::right()
{
    if(m_st == 1)
        return;
    else if(m_st == 0)
        move(1);
    else
        move(2);
}

void Dir::left()
{
    if(m_st == 2)
        return;
    else if(m_st == 0)
        move(-1);
    else
        move(-2);
}

void Dir::center()
{
    if(m_st == 0)
        return;
    else if(m_st == 1)
        move(-1);
    else
        move(1);
}

void Dir::move(int nb)
{
    int steps = nb * 25;
    if(steps < 0)
        steps *= -1;
    int dir = 0;
    if(nb < 0)
        dir = 1;

    int act = 0;
    for(int i = 0; i < steps; ++i) {
        for(int j = 2; j < 6; ++j)
            digitalWrite(j, LOW);
        digitalWrite(act, HIGH);

        if(dir == 1) {
            ++act;
            act %= 4;
        }
        else {
            --act;
            act += 4;
            act %= 4;
        }

        delay(50);
    }
}

