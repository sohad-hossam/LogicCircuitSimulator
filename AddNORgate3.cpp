#include "AddNORgate3.h"
#include"ApplicationManager.h"

AddNORgate3::AddNORgate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddNORgate3::~AddNORgate3(void)
{
}

void AddNORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	while ((Cy <= UI.ToolBarHeight) || (Cx <= UI.ToolBarHeight) || (Cy >= (UI.height - UI.ToolBarHeight)))
	{
		pOut->PrintMsg("You cannot add gates here, please click on the drawing area to add your gate");
		pIn->GetPointClicked(Cx, Cy);
	}

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	NOR3* pA = new NOR3(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddNORgate3::Undo()
{}

void AddNORgate3::Redo()
{}

