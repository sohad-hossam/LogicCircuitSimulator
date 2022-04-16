#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"

class Connection :	public Component
{
	//Component*	SrcCmpnt;	//Connection source component
	//Component*	DstCmpnt;	//Connection Destination component
	//int		DstPin;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
public:
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin);

	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);	//for each component to Draw itself

	
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getOutputPin();//sourcepin
	InputPin* getInputPin();//destpin


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual InputPin* getInputPin(int pinnumber);
	void setOutputPinStatus(STATUS s);
	 InputPin* checkInputPinClick(float x, float y, GraphicsInfo& pinGfxInfo);//Check if user clicked on input pin
	 OutputPin* checkOutputPinClick(float x, float y, GraphicsInfo& pinGfxInfo);//check if user clicked on output pin

	 bool CheckInsideArea(float x, float y);
	 void disconnect();
	 virtual void save(ofstream& out);
	 void save(ofstream& out, int OutGateID);
	 virtual int getInputPinNo(GraphicsInfo gf);
	 virtual void load(ifstream& in);
};
