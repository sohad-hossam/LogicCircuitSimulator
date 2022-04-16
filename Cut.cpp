#include "Cut.h"
Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Cut Gate");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Cut::Execute()
{
	ReadActionParameters();
	GraphicsInfo GInfo; //Gfx info to be used to select
	Component* p;
	p = pManager->InsideArea(x, y);
	if (p != NULL)
	{
		pManager->setCpdComp(p);
	}
	pManager->setindicator(2);
}

void Cut::Undo()
{}

void Cut::Redo()
{}
