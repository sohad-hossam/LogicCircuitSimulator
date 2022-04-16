#include "Paste.h"
#include"Components/AND2.h"
#include"AND3.h"
#include"Buff.h"
#include"INV.h"
#include"NAND2.h"
#include "NOR2.h"
#include "NOR3.h"
#include "OR2.h"
#include "Switch.h"
#include "XNOR2.h"
#include "XOR2.h"
#include "XOR3.h"
#include"LED.h"
Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
}

Paste::~Paste(void)
{
}

void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Paste Gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Paste::Execute()
{
	ReadActionParameters();
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to select

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;

	Component* p = pManager->getCpdComp();
	switch (pManager->getindicator())
	{
	case 1:
		if (dynamic_cast<AND2*>(p) != NULL)
		{
			AND2* pAct = new AND2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<AND3*>(p) != NULL)
		{
			AND3* pAct = new AND3(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<Buff*>(p) != NULL)
		{
			Buff* pAct = new Buff(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<INV*>(p) != NULL)
		{
			INV* pAct = new INV(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<LED*>(p) != NULL)
		{
			LED* pAct = new LED(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<NAND2*>(p) != NULL)
		{
			NAND2* pAct = new NAND2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<NOR2*>(p) != NULL)
		{
			NOR2* pAct = new NOR2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<NOR3*>(p) != NULL)
		{
			NOR3* pAct = new NOR3(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<OR2*>(p) != NULL)
		{
			OR2* pAct = new OR2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<Switch*>(p) != NULL)
		{
			Switch* pAct = new Switch(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<XNOR2*>(p) != NULL)
		{
			XNOR2* pAct = new XNOR2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<XOR2*>(p) != NULL)
		{
			XOR2* pAct = new XOR2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
		else if (dynamic_cast<XOR3*>(p) != NULL)
		{
			XOR3* pAct = new XOR3(GInfo, AND2_FANOUT);
			pManager->AddComponent(pAct);
		}
	case 2:
		
		if (p != NULL && pManager->getindicator()==2)
		{
			p->setGraphicsInfo(GInfo);
			Gate* g = dynamic_cast<Gate*>(p);
			pManager->DeletegateConnections(g);
		}
	}
}

void Paste::Undo()
{}

void Paste::Redo()
{}

