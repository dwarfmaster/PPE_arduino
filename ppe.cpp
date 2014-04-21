#include "Arduino.h"
#include "dir.hpp"
#include "bt.hpp"

void setup();
void loop();

int main(void)
{
    init();

#if defined(USBCON)
    USBDevice.attach();
#endif
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    Serial.begin(9600);

    Dir dir;
    Bluetooth bt;
    digitalWrite(13, HIGH);
    bt.connect(0);
    digitalWrite(13, LOW);
    delay(1000);

    for(;;)
    {
        if(Serial.available()) {
            /* Parsing command. */
            char cg = Serial.read();
            unsigned char c = cg;
            if((c & 0xF0) == 0x50) {
                c &= 0x0F;
                switch(c) {
                    case 0x00: dir.left();   break;
                    case 0x01: dir.right();  break;
                    case 0x02: dir.center(); break;
                    case 0x03: break; // Stop
                    case 0x04: break; // Going forward
                    case 0x05: break; // Alert
                    default:   break; // Shouldn't and mustn't happen
                }
            }
            else
                Serial.print(" Wrong format ");
        }

        if(bt.connected()) {
            char c;
            while(bt.read(&c))
                Serial.write(c);
            digitalWrite(13, HIGH);
        }
        else {
            digitalWrite(13, LOW);
            bt.connect(0);
        }
    }
}

