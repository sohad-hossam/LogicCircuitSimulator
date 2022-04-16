#include "AddConnection.h"
#include"ApplicationManager.h"


AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to add the Connection");

	//Wait for User Input

	pIn->GetPointClicked(x1, y1);

	pIn->GetPointClicked(x2, y2);
	
	//gets index of chosen comp
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	InputPin* in;
	OutputPin* out;
	GraphicsInfo GInfo2;

	in = pManager->checkInputPinClick(x2, y2, GInfo2);
	out = pManager->checkOutputPinClick(x1, y1, GInfo2);
	if (in != NULL && out != NULL )
	{

		if (in->getConnected() == false)
		{
			Connection* pA = new Connection(GInfo2, out, in);
			if (out->ConnectTo(pA))
			{
				pManager->AddComponent(pA);
				in->setConnected(true);
			}
			else
			{
				delete pA;
			}
		}
	}
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

