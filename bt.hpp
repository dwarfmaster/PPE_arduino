
#ifndef DEF_BT
#define DEF_BT

#include <Arduino.h>
#include <SoftwareSerial.h>

class Bluetooth
{
	public:
		Bluetooth();
        /** @brief Will wait for an incoming connexion.
         * @param timeout If different from 0, the number of millis after the waiting must stop.
         * @return True if a connection was established, false otherwise.
         */
		bool connect(unsigned int timeout);
        /** @brief Indicates if the connection is established. */
        bool connected();
        /** @brief Read a character from the bt buffer. */
		bool read(char* c);
        /** @brief Send data to the connected device. */
        void write(char c);

	private:
		SoftwareSerial m_btcard;
};

#endif//DEF_BLUETOOTH

