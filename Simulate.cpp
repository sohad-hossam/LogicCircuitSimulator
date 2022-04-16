#include "Simulate.h"
#include "ApplicationManager.h"
#include"ChangeSwitch.h"

Simulate::Simulate(ApplicationManager* pApp) :Action(pApp)
{
}

Simulate::~Simulate(void)
{
}

void Simulate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	if (pManager->CheckFloatingPins())
	{
		if (UI.AppMode == DESIGN)
		{

			pOut->PrintMsg("Simulating the circuit");
			pOut->ClearDesignToolbar();
			pOut->CreateSimulationToolBar();
		}
		else
		{
			pOut->PrintMsg("Designing the circuit");
			pOut->ClearSimulationbar();
			pOut->CreateDesignToolBar();
		}


		//Clear Status Bar
		pOut->ClearStatusBar();
	}
}

void Simulate::Execute()
{
	ReadActionParameters();
	if(UI.AppMode==SIMULATE)
		pManager->OperateCircuit();
}

void Simulate::Undo()
{}

void Simulate::Redo()
{}

