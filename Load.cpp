#include "Load.h"
#include "ApplicationManager.h"

Load::Load(ApplicationManager* pApp) :Action(pApp)
{

}

Load::~Load(void)
{
}

void Load::ReadActionParameters()
{
}

void Load::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	inputFile.open("Saving file.txt", ios::in);

	if (inputFile.fail())
	{
		pOut->PrintMsg("Error loading file");
		exit(1);
	}
	pManager->load(inputFile);

}

void Load::Undo()
{}

void Load::Redo()
{}
