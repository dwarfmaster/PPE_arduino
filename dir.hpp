
#ifndef DEF_DIR
#define DEF_DIR

#include "Arduino.h"

/* Manage the direction, uses the pins 2, 3, 4, 5. */
class Dir
{
    public:
        Dir();

        void right();
        void left();
        void center();

    private:
        /* The actual direction : 0 = center, 1 = right, 2 = left */
        int m_st;
        /* Makes the directionnal motor move : nb is the number of 45 degres to do,
         * negative values are accepted.
         */
        void move(int nb);
};

#endif

