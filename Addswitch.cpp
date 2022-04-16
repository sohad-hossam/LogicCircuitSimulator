#include "Addswitch.h"
#include"ApplicationManager.h"


Addswitch::Addswitch(ApplicationManager* pApp) :Action(pApp)
{
}

Addswitch::~Addswitch(void)
{
}

void Addswitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Switch: Click to add the gate");

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

void Addswitch::Execute()
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
	Switch* pA = new Switch(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void Addswitch::Undo()
{}

void Addswitch::Redo()
{}

