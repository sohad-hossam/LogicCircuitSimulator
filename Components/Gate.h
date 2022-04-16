#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	bool hasOperated; 
public:
	Gate(int r_Inputs, int r_FanOut);
	InputPin* checkInputPinClick(float x, float y, GraphicsInfo &pinGfxInfo); //Check if user clicked on input pin
	OutputPin* checkOutputPinClick(float x, float y, GraphicsInfo& pinGfxInfo);//check if user clicked on output pin
	bool CheckInsideArea(float x, float y);//checks if point clicked is inside the area
	InputPin* getInputPin(int i);
	OutputPin* getOutputPin();
	int getNumberofInputs();
	void CheckInputPinsOperation();
	bool isOutputPin(OutputPin* OP);
	virtual int getInputPinNo(GraphicsInfo gf);
	bool checkisReady();
	void setInputsReady(bool);
	bool getHasOperated();
	void setHasOperated(bool);
	void setOutputPinStatus(STATUS s);
    void getPinCoordinates(int pinnumber, GraphicsInfo& pinGfxInfo);
	void getOutputPinCoordinates(GraphicsInfo& pinGfxInfo);
};

#endif
