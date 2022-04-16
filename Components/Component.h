#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "InputPin.h"
#include "OutputPin.h"
#include <fstream>
using namespace std;

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool selected;// indicates wether component is selected or not
	bool operatenow;
	bool todrawstring;
	int ID;
	static int tmpindex;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	void setSelected(bool s);
	bool getSelected();
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual void save(ofstream& out) = 0;
	virtual void load(ifstream& in) = 0;
	void setLabel(string);
	string getLabel();
	void setGraphicsInfo(GraphicsInfo x);// sets the graphics info
	GraphicsInfo getinfo();
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setOutputPinStatus(STATUS s) = 0; //sets outputpin status
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* getOutputPin() = 0;
	virtual InputPin* getInputPin(int pinnumber) = 0;
	virtual InputPin* checkInputPinClick(float x, float y, GraphicsInfo& pinGfxInfo) = 0; //Check if user clicked on input pin
	virtual OutputPin* checkOutputPinClick(float x, float y, GraphicsInfo& pinGfxInfo) = 0;//check if user clicked on output pin
	
	virtual bool CheckInsideArea(float x, float y) = 0;// checks if the point clicked was inside the component
	Component();

	virtual int getInputPinNo(GraphicsInfo gf) = 0;
	
	int  getID();
	void setID(int tmpindex);

	void SetOperateNow(bool);
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
