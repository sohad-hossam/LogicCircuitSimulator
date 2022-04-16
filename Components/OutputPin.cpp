#include "OutputPin.h"
#include "Connection.h"

OutputPin::OutputPin(int r_FanOut)
{
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS: r_FanOut;	//set the fan out of the pin.
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if(m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
	}
	
	return false;	//can't connect to any more connections
}

void OutputPin::knowifReady()
{
	for (int i = 0; i < m_Conn; i++)
	{
		InputPin* ip = m_Connections[i]->getInputPin();
		ip->setStatus(m_Status);
		ip->setisReady(1);
	}
}

void OutputPin::Disconnected(Connection* conn)
{
	int x;
	for (int i = 0; i < m_Conn; i++)
	{
		if (conn == m_Connections[i])
		{
			x = i;
		}
	}

	if (x < m_Conn)
	{
		for (int j = x; j < m_Conn - 1; j++)
		{
			m_Connections[j] = m_Connections[j + 1];
		}
		m_Connections[m_Conn] = NULL;
		m_Conn--;
	}
}

int OutputPin::getm_Conn()
{
	return m_Conn;
}
