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
        char c = Serial.read();
        /* Write back, and add the result of parsing. */
        Serial.write(c);
        if(c & 0xf0 == 0xf0) { /* Turn order. */
            if(c & 0x0f == 0x01)
                Serial.println("Turning left !");
            else
                Serial.println("Turning right !");
        }
        else if(c & 0xa0 == 0xa0) { /* Move order. */
            if(c & 0x0f == 0x01)
                Serial.println("Going forward !");
            else if(c & 0x0f == 0x00)
                Serial.println("Stopping !");
        }
        else if(c == 0x00) { /* Alert order. */
            Serial.println("Alert !");
        }
    }
    
    /* TODO write incoming bluetooth data to Serial. */
}


