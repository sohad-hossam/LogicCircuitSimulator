#include "Select.h"
Select::Select(ApplicationManager* pApp) :Action(pApp)
{
}

Select::~Select(void)
{
}

void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("click on Gate or connection to select or unselect");
	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Select::Execute()
{
	ReadActionParameters();
	GraphicsInfo GInfo; //Gfx info to be used to select
	Component* p;
	p = pManager->InsideArea(x, y);
	if (p != NULL)
		if (p->getSelected() == true)
		{
			p->setSelected(false);

		}
		else
		{
			p->setSelected(true);
		}
}

void Select::Undo()
{}

void Select::Redo()
{}