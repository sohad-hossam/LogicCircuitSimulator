#include "Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	selected = false;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getOutputPin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getInputPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo, getSelected());
	if (getLabel() != "")
	{
		if (getLabel() != "")
		{
			pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 6, getLabel());
		}
	}
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::setOutputPinStatus(STATUS s)
{
}

InputPin* Connection::checkInputPinClick(float x, float y, GraphicsInfo& pinGfxInfo)
{
	return nullptr;
}

OutputPin* Connection::checkOutputPinClick(float x, float y, GraphicsInfo& pinGfxInfo)
{
	return nullptr;
}

bool Connection::CheckInsideArea(float x, float y)
{
	if (x > m_GfxInfo.x1   && x< m_GfxInfo.x2  && y> m_GfxInfo.y1 - 80 && y < m_GfxInfo.y2 + 50 )
		return true;
	else if (x > m_GfxInfo.x1 -10  && x< m_GfxInfo.x2 + 50 && y> m_GfxInfo.y1  && y < m_GfxInfo.y2 )
		return true;
	else
		return false;
}

void Connection::disconnect()
{
	DstPin->setConnected(false);
	SrcPin->Disconnected(this);
}

void Connection::save(ofstream& out, int outGateID)
{
	out << outGateID << "\t" << (DstPin->getComponent())->getID() << "\t" << (DstPin->getComponent())->getInputPinNo(m_GfxInfo) << endl;
}

InputPin* checkInputPinClick(float x, float y, GraphicsInfo& pinGfxInfo)
{
	return NULL;
}

void Connection::save(ofstream& out)
{

}

void Connection::load(ifstream& in)
{

}

int Connection::getInputPinNo(GraphicsInfo gf)
{
	return 0;
}

InputPin* Connection::getInputPin(int pinnumber)
{
	return NULL;
}