#include "OR2.h"
OR2::OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	tmpindex++;
	setID(tmpindex);
}


void OR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	if(GetInputPinStatus(1)==0&& GetInputPinStatus(2)==0)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
	m_OutputPin.knowifReady();

}


// Function Draw
// Draws 2-input AND gate
void OR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(m_GfxInfo, getSelected());
	if (getLabel() != "")
	{
		pOut->DrawString(m_GfxInfo.x1 + 15, m_GfxInfo.y1 - 15, getLabel());
	}
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void OR2::save(ofstream& out)
{
	out << "OR2" << "\t" << getID() << "\t" << (getLabel() == "" ? "$" : getLabel()) << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
}

void OR2::load(ifstream& in)
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
