#include "Gate.h"
#include "../LED.h"
//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	hasOperated = false;
	selected = false;

	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}


InputPin* Gate::checkInputPinClick(float x, float y, GraphicsInfo& pinGfxInfo)
{
	if (m_Inputs == 0) return NULL;
	else if (m_Inputs == 1)
	{
		if (x > (m_GfxInfo.x1 - 10) && x<(m_GfxInfo.x1+5) && y>(m_GfxInfo.y1 ) && y < (m_GfxInfo.y1 + 30))
		{

			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 25;
			return &m_InputPins[0];
		}

	}
	else if (m_Inputs == 2)
	{
		if (x <= (m_GfxInfo.x1 + 20) && x>= (m_GfxInfo.x1 - 5) && y >= (m_GfxInfo.y1 + 10) && y <= (m_GfxInfo.y1 + 15))
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y1 + 12.5;
			return &m_InputPins[0];
		}
		else if (x <= (m_GfxInfo.x1 + 15) && x >= (m_GfxInfo.x1 - 5) && y >= (m_GfxInfo.y2 - 20) && y <= (m_GfxInfo.y2 - 10))
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 16;
			return &m_InputPins[1];
		}
	}
	else if (m_Inputs == 3)
	{
		if (x < (m_GfxInfo.x1 + 10) && x>m_GfxInfo.x1 && y > (m_GfxInfo.y1 + 10) && y < (m_GfxInfo.y1 + 15))
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 45;
			return &m_InputPins[0];
		}
		else if (x < (m_GfxInfo.x1 + 10) && x>m_GfxInfo.x1 && y > (m_GfxInfo.y1 + 20) && y < (m_GfxInfo.y1 + 25))
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 25;
			return &m_InputPins[1];
		}
		else if (x < (m_GfxInfo.x1 + 10) && x>m_GfxInfo.x1 && y > (m_GfxInfo.y2 - 20) && y  < (m_GfxInfo.y2 - 10))
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 12;
			return &m_InputPins[2];
		}
	}
	return NULL;
}

OutputPin* Gate::checkOutputPinClick(float x, float y, GraphicsInfo& pinGfxInfo)
{
	if (x > (m_GfxInfo.x2 - 10) && x<m_GfxInfo.x2 && y>(m_GfxInfo.y2 - 30) && y < (m_GfxInfo.y2 - 20))
	{

		pinGfxInfo.x1 = m_GfxInfo.x2;
		pinGfxInfo.y1 = m_GfxInfo.y2 - 25;
		return &m_OutputPin;
	}
	return NULL;
}
bool Gate::CheckInsideArea(float x, float y)
{
	if (x > m_GfxInfo.x1 && x< m_GfxInfo.x2 && y> m_GfxInfo.y1 && y < m_GfxInfo.y2)
		return true;
	else
		return false;
}

InputPin* Gate::getInputPin(int i)
{
	if (i < m_Inputs)
	{
		return &m_InputPins[i];
	}
	else
		return NULL;
}

OutputPin* Gate::getOutputPin()
{
	return &m_OutputPin;
}

int Gate::getNumberofInputs()
{
	return m_Inputs;
}


void Gate::CheckInputPinsOperation()
{
	bool operate = true;
	for (int i = 0; i < m_Inputs; i++)
	{
		if (!m_InputPins[i].getisReady())
			operate = false;
	}

	if (operate)
		operatenow = true;
}

bool Gate::isOutputPin(OutputPin* OP)
{
	if (OP == &m_OutputPin)
		return true;
	return false;
}

int Gate::getInputPinNo(GraphicsInfo gf)

{
	if (m_Inputs == 0)
		return 0;
	else if (m_Inputs == 1)
	{
		return 1;
	}
	else if (m_Inputs == 2)
	{
		if (gf.x2 = m_GfxInfo.x1 && (gf.y2 = m_GfxInfo.y1 + 12.5))
			return 1;
		else if(gf.x2 = m_GfxInfo.x1 && (gf.y2 = m_GfxInfo.y2 - 16))
			return 2;
	}
	else if (m_Inputs == 3)
	{
		if (gf.x2 = m_GfxInfo.x1 && (gf.y2 = m_GfxInfo.y2 - 45))
			return 1;
		else if (gf.x2 = m_GfxInfo.x1 && (gf.y2 = m_GfxInfo.y2 - 25))
			return 2;
		else if (gf.x2 = m_GfxInfo.x1 && (gf.y2 = m_GfxInfo.y2 - 12))
			return 3;
	}
}

bool Gate::checkisReady()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (!(m_InputPins[i].getisReady()))
		{
			return 0;
		}
	}
	return true;
}

void Gate:: setInputsReady(bool b )
{
	for (int i = 0; i< m_Inputs;i++)
	{
		m_InputPins[i].setisReady(b);
	}

}

bool Gate::getHasOperated()
{
	return hasOperated;
}

void Gate::setHasOperated(bool has)
{
	hasOperated = has;
}

void Gate::setOutputPinStatus(STATUS s)
{

}

void Gate::getPinCoordinates(int pinnumber, GraphicsInfo& pinGfxInfo)
{
	 if (m_Inputs == 1)
	{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 25;
	}
	else if (m_Inputs == 2)
	{
		if (pinnumber==1)
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y1 + 12.5;
		}
		else if (pinnumber==2)
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 16;
		}
	}
	else if (m_Inputs == 3)
	{
		if (pinnumber==1)
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 45;
		}
		else if (pinnumber==2)
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 25;
		}
		else if (pinnumber==3)
		{
			pinGfxInfo.x2 = m_GfxInfo.x1;
			pinGfxInfo.y2 = m_GfxInfo.y2 - 12;
		}
	}
}

void Gate::getOutputPinCoordinates(GraphicsInfo& pinGfxInfo)
{
	pinGfxInfo.x1 = m_GfxInfo.x2;
	pinGfxInfo.y1 = m_GfxInfo.y2 - 25;
}
