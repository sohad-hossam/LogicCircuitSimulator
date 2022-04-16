#include "Copy.h"
Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy(void)
{
}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Copy Gate");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Copy::Execute()
{
	ReadActionParameters();
	GraphicsInfo GInfo; //Gfx info to be used to select
	Component* p;
	p = pManager->InsideArea(x, y);
	if (p != NULL)
	{
		pManager->setCpdComp(p);
	}
	pManager->setindicator(1);
}

void Copy::Undo()
{}

void Copy::Redo()
{}
