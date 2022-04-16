#include "ChangeSwitch.h"
#include "ApplicationManager.h"
#include"Switch.h"
ChangeSwitch::ChangeSwitch(ApplicationManager* pApp) :Action(pApp)
{
}

ChangeSwitch::~ChangeSwitch(void)
{
}

void ChangeSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string str1 = "n";
	//Print Action Message
	pOut->PrintMsg("Click on a switch");
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void ChangeSwitch::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	GraphicsInfo GInfo;
	Component* s = pManager->InsideArea(Cx, Cy);
	if (dynamic_cast<Switch*>(s))
	{
		if (s->GetOutPinStatus() == LOW)
			s->setOutputPinStatus(HIGH);
		else
			s->setOutputPinStatus(LOW);
	}
	pManager->OperateCircuit();
}

void ChangeSwitch::Undo()
{}

void ChangeSwitch::Redo()
{}

