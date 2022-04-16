#include "Delete.h"
#include"ApplicationManager.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}

Delete::~Delete(void)
{
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Delete gate");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Delete::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Component* p;
	p = pManager->InsideArea(x, y);
	if (p != NULL)
	{
		pManager->DeleteComponent(x, y);
	}
	
}

void Delete::Undo()
{}

void Delete::Redo()
{}

