
#include "Edit.h"
#include "ApplicationManager.h"
#include"Components/Connection.h"

Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{

}

Edit::~Edit(void)
{
}

void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Edit");
	//Print Action Message
	Component* c;
	string str1 = "n";
	pIn->GetPointClicked(Cx, Cy);
	c = pManager->InsideArea(Cx, Cy);
	if (c != NULL)
	{
		if (dynamic_cast<Gate*>(c))
		{
			if (c->getLabel() != "")
			{
				do
				{
					pOut->PrintMsg("Select Component you want to edit its label:");
					//Wait for User InputpIn->GetPointClicked(Cx, Cy);
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
				pOut->PrintMsg("Editing label");
				string str2 = c->getLabel();
				string str = pIn->editString(pOut, str2);

				c->setLabel(str);
			}
		}
		else
		{
			pOut->PrintMsg("Choose what to edit in the Connection: 1-Edit Label. 2-Edit Connection Pins");
			string str = pIn->GetSrting(pOut);
			if (str == "2")
			{
				pOut->PrintMsg("Edit Connection Pins");
				pIn->GetPointClicked(x1, y1);
				pIn->GetPointClicked(x2, y2);
				GraphicsInfo GI;
				Connection* conn = dynamic_cast<Connection*>(c);
				InputPin* in = pManager->checkInputPinClick(x2, y2, GI);
				OutputPin* out = pManager->checkOutputPinClick(x1, y1, GI);
				if (out != NULL && in != NULL)
				{
					conn->disconnect();
					conn->setSourcePin(out);
					out->ConnectTo(conn);
					conn->setDestPin(in);
					in->setConnected(true);
					c->setGraphicsInfo(GI);
				}
			}
			else if (str == "1" && c->getLabel() != "")
			{
				pOut->PrintMsg("Edit Connection Label");
				do
				{
					pOut->PrintMsg("Select Component you want to edit its label:");
					//Wait for User InputpIn->GetPointClicked(Cx, Cy);
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
				pOut->PrintMsg("Editing label");
				string str2 = c->getLabel();
				string str = pIn->editString(pOut, str2);

				c->setLabel(str);
			}

		}


	}

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Edit::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();


	
}

void Edit::Undo()
{}

void Edit::Redo()
{}