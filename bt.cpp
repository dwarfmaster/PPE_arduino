#include "bt.hpp"

Bluetooth::Bluetooth()
	: m_btcard(6,7), m_connected(false)
{
	m_btcard.begin(38400);
	m_btcard.print("\r\n+STWMOD=0\r\n");
	m_btcard.print("\r\n+STNA=PPEFermat\r\n");
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
    m_connected = false;
    char c;
	while(!read(&c))
	{
		if( timeout > 0 && millis() - last > timeout )
			return false;
	}
	
    m_connected = true;
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
	return m_connected;
}


