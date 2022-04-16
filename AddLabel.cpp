
#include "AddLabel.h"
#include "ApplicationManager.h"

AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp)
{

}

AddLabel::~AddLabel(void)
{
}

void AddLabel::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	string str1 = "n";
	Component* c;
	do
	{
		pOut->PrintMsg("Select Component to add label on:");
		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);
		c = pManager->InsideArea(Cx, Cy);
		if (!c)
		{
			pOut->PrintMsg("You did not select any component");
			pOut->PrintMsg("Do you want to repeat the process(y/n)?");
			if (str1 == "n")
			{
				pOut->PrintMsg("Thank you");
				return;
			}
		}
	} while (str1 == "y");
	pOut->PrintMsg("enter label");
	string str = pIn->GetSrting(pOut);

	c->setLabel(str);

	pManager->UpdateInterface();




	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLabel::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();


	/*AddLabel *pA=new AddLabel(GInfo);
	pManager->AddComponent(pA);*/
}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}