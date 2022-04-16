#include "LED.h"
LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	tmpindex++;
	setID(tmpindex);
}


void LED::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	
}


// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (m_InputPins[0].getStatus() == 0)
		pOut->DrawLED(m_GfxInfo, getSelected());
	else
		pOut->DrawLEDON(m_GfxInfo, getSelected());
	if (getLabel() != "")
	{
		pOut->DrawString(m_GfxInfo.x1 + 15, m_GfxInfo.y1 - 15, getLabel());
	}
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void LED::save(ofstream& out)
{
	out << "LED" << "\t" << getID() << "\t" << (getLabel() == "" ? "$" : getLabel()) << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
}

void LED::load(ifstream& in)
{
	int m_id;
	in >> m_id;
	setID(m_id);
	string m_Label;
	in >> m_Label;
	if (m_Label != "$")
	{
		setLabel(m_Label);
	}
	int x1, y1;
	in >> x1;
	in >> y1;
	m_GfxInfo.x1 = x1;
	m_GfxInfo.y1 = y1;
	m_GfxInfo.x2 = x1 + 50;
	m_GfxInfo.y2 = y1 + 50;
}
