#include "Switch.h"
Switch::Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	tmpindex++;
	setID(tmpindex);
}


void Switch::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	m_OutputPin.knowifReady();

}


// Function Draw
// Draws 2-input AND gate
void Switch::Draw(Output* pOut )
{
	//Call output class and pass gate drawing info to it.
	if (m_OutputPin.getStatus() == 0)
		pOut->Drawswitch(m_GfxInfo, getSelected());
	else
		pOut->DrawswitchON(m_GfxInfo, getSelected());
}

//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

void Switch::setOutputPinStatus(STATUS s)
{
	m_OutputPin.setStatus(s);
}


//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)
{
	return -1;//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void Switch::save(ofstream& out)
{
	out << "Switch" << "\t" << getID() << "\t" << (getLabel() == "" ? "$" : getLabel()) << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
}

void Switch::load(ifstream& in)
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

