#include "Save.h"
#include "ApplicationManager.h"

Save::Save(ApplicationManager *pApp):Action(pApp)
{
	
}

Save::~Save(void)
{
}

void Save::ReadActionParameters()
{	
}

void Save::Execute()
{
	outputfile.open("Saving file.txt");
	
	pManager->SaveAll(outputfile);
	outputfile<<"-1";
	outputfile.close();
			
}

void Save::Undo()
{}

void Save::Redo()
{}
