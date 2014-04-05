#include "Arduino.h"

void setup();
void loop();

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
                case 0x00: Serial.print(" Turning left ");   break;
                case 0x01: Serial.print(" Turning right ");  break;
                case 0x02: Serial.print(" Stopping ");       break;
                case 0x03: Serial.print(" Moving forward "); break;
                case 0x04: Serial.print(" Alert ! ");        break;
                default:   Serial.print(" Invalid ");        break;
            }
        }
        else
            Serial.print(" Wrong format ");
    }

    /* TODO write incoming bluetooth data to Serial. */
}


