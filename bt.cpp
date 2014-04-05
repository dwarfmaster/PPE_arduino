#include "bt.hpp"

Bluetooth::Bluetooth()
	: m_btcard(6,7)
{
	pinMode(6, INPUT);
	pinMode(7, OUTPUT);

	m_btcard.begin(38400);
	m_btcard.print("\r\n+STWMOD=0\r\n");
	m_btcard.print("\r\n+STNA=PPEFermatRobot\r\n");
	m_btcard.print("\r\n+STOAUT=1\r\n");
	m_btcard.print("\r\n+STAUTO=0\r\n");
	delay(2000);

	m_btcard.print("\r\n+INQ=1\r\n");
	delay(2000);
	m_btcard.flush();
}

bool Bluetooth::connect(unsigned int timeout)
{
	unsigned int last = millis();
	while( !connected() )
	{
		if( timeout > 0 && millis() - last > timeout )
			return false;
	}
	
	return true;
}

bool Bluetooth::read(char* c)
{
	if(!m_btcard.available())
        return false;
    *c = m_btcard.read();
	return true;
}

bool Bluetooth::connected()
{
	return m_btcard.isListening();
}


