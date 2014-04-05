#include "Arduino.h"
#include "dir.hpp"

void setup();
void loop();

Dir dir;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if(Serial.available()) {
        /* Parsing command. */
        char cg = Serial.read();
        unsigned char c = cg;
        /* Write back, and add the result of parsing. */
        Serial.write(c);
        if((c & 0xF0) == 0x50) {
            c &= 0x0F;
            switch(c) {
                case 0x00: dir.left();   break;
                case 0x01: dir.right();  break;
                case 0x02: dir.center(); break;
                case 0x03: Serial.print(" Stopping ");       break;
                case 0x04: Serial.print(" Moving forward "); break;
                case 0x05: Serial.print(" Alert ! ");        break;
                default:   Serial.print(" Invalid ");        break;
            }
        }
        else
            Serial.print(" Wrong format ");
    }

    /* TODO write incoming bluetooth data to Serial. */
}


