#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "AddANDgate3.h"
#include "AddBuffgate.h"
#include "AddINVgate.h"
#include "AddNANDgate2.h"
#include "AddNORgate2.h"
#include "AddNORgate3.h"
#include "AddORgate2.h"
#include "Addswitch.h"
#include "AddXORgate2.h"
#include "AddXNORgate2.h"
#include "AddXORgate3.h"
#include"AddLED.h"
#include"AddConnection.h"
#include"Select.h"
#include"Delete.h"
#include"Copy.h"
#include"Paste.h"
#include"Cut.h"
#include"Components/Connection.h"
#include "LED.h"
#include "Save.h"
#include "AddLabel.h"
#include "Load.h"
#include"ChangeSwitch.h"
#include "Simulate.h"
#include "Edit.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	CpdComp = NULL;
	indicator = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_Buff:
			pAct = new AddBuffgate(this);
			break;
		case ADD_INV:
			pAct = new AddINVgate(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_Switch:
			pAct = new Addswitch(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;
		case ADD_LED:
			pAct = new AddLED(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
		case SIM_MODE:
			pAct = new Simulate(this);
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case DEL:
			pAct= new Delete(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case SAVE:
			pAct = new Save(this);
			break;
		case ADD_Label:
			pAct = new AddLabel(this);
			break;
		case LOAD:
			pAct = new Load(this);
			break;
		case CHANGE_SWITCH:
			pAct = new ChangeSwitch(this);
			break;
		case EDIT:
			pAct = new Edit(this);
			break;
		case EXIT:
			delete pAct;
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////
OutputPin* ApplicationManager::checkOutputPinClick(float x, float y, GraphicsInfo& pinGfxInfo)
{
	OutputPin* outPin = NULL;
	int i = 0;
	while (outPin == NULL && i < CompCount)
	{
		outPin = CompList[i]->checkOutputPinClick(x, y, pinGfxInfo);
		i++;
	}
	return outPin;
}
////////////////////////////////////////////////////////////////////
InputPin* ApplicationManager::checkInputPinClick(float x, float y, GraphicsInfo& pinGfxInfo)
{
	InputPin* inPin = NULL;
	int i = 0;
	while (inPin == NULL && i < CompCount)
	{
		inPin = CompList[i]->checkInputPinClick(x, y, pinGfxInfo);
		i++;
	}
	return inPin;
}

Component* ApplicationManager::InsideArea(float x, float y)
{
	int i = 0;
	while (i < CompCount)
	{
		if (CompList[i]->CheckInsideArea(x, y))
			return CompList[i];
		i++;
	}
	return NULL;
}


void ApplicationManager::DeleteComponent(float x, float y)
{
	int i = 0;
	while (i < CompCount && CompList[i]!=NULL)
	{
		if (CompList[i]->CheckInsideArea(x, y))
		{
			delete CompList[i];
			CompList[i] = NULL;
		}
		else
			i++;
	}

	if (i < CompCount)
	{
		ShiftCompList(i);
	}
}

void ApplicationManager::ShiftCompList(int i)
{
	if (i < CompCount)
	{
		for (int j = i; j < CompCount - 1; j++)
		{
			CompList[j] = CompList[j + 1];
		}
		CompList[CompCount] = NULL;
		CompCount--;
	}
}

int ApplicationManager::getnumberofConnections()
{
	int count = 0;
	for (int i = 0; i < CompCount; i++)
	{
		Connection* c = dynamic_cast<Connection*>(CompList[i]);
		if (c)
		{
			count++;
		}
	}
	return count;
}

bool ApplicationManager::CheckFloatingPins()
{
	for (int i = 0; i < CompCount; i++)
	{
		Gate* gate = dynamic_cast<Gate*>(CompList[i]);
		if (dynamic_cast<Gate*>(CompList[i]))
		{
			for (int j = 0; j < gate->getNumberofInputs(); j++)
			{
				if (!gate->getInputPin(j)->getConnected())
					return false;
			}
			int noofCon=gate->getOutputPin()->getm_Conn();
			if (noofCon == 0 && !dynamic_cast<LED*>(gate))
				return false;
		}
	}
}

void ApplicationManager::setCpdComp(Component* s)
{
	CpdComp = s;
}

Component* ApplicationManager::getCpdComp()
{
	return CpdComp;
}

void ApplicationManager::setindicator(int s)
{
	indicator = s;
}

int ApplicationManager::getindicator()
{
	return indicator;
}


void ApplicationManager::DeletegateConnections(Gate* gPtr)
{
	int i = 0;
	bool deleted = false;
	//gets connections connected to gate, compares them to the input and output pins to delete them
	while(i < CompCount)
	{
		Connection* conn = dynamic_cast<Connection*>(CompList[i]);
		if (conn != NULL)
		{
			InputPin* IP = conn->getInputPin();
			for (int j = 0; j < gPtr->getNumberofInputs(); j++)
			{
				if (IP == gPtr->getInputPin(j))
				{
					conn->disconnect();
					delete conn;
					conn = NULL;
					ShiftCompList(i);
					deleted = true;
				}
			}
			if (conn != NULL)
			{
				OutputPin* OP = conn->getOutputPin();
				if (OP == gPtr->getOutputPin())
				{
					conn->disconnect();
					delete conn;
					ShiftCompList(i);
					deleted = true;
				}
			}

		}
		if (deleted)
		{
			i = 0;
			deleted = false;
		}
		else
			i++;
	}
}

Component* ApplicationManager::getGateFromOutputPin(OutputPin* OP)
{
	for (int i = 0; i < CompCount; i++)
	{
		Gate* gPtr = dynamic_cast<Gate*>(CompList[i]);
		if (gPtr != NULL)
		{
			if (gPtr->isOutputPin(OP))
				return gPtr;
		}
	}
	return NULL;
}

void ApplicationManager::SaveAll(ofstream& out)
{
	out << CompCount- getnumberofConnections() << endl;
	out << endl;
	for (int i = 0; i < CompCount; i++)
	{
		Gate* g = dynamic_cast<Gate*>(CompList[i]);
		if (g)
			CompList[i]->save(out);
	}
	out << "Connections" << endl;
	for (int i = 0; i < CompCount; i++)
	{
		Connection* c = dynamic_cast<Connection*>(CompList[i]);
		if (c)
		{
			int id = getGateFromOutputPin(c->getOutputPin())->getID();
			c->save(out, id);
		}
	}
}

void ApplicationManager::load(ifstream& in) {
	for (int i = 0; i < CompCount; i++)
	{
		delete CompList[i];
		CompList[i] = NULL;
	}
	CompCount = 0;

	string componentType;
	int Ccount;
	in >> Ccount;
	int idnumber;
	int tmpx1;
	int tmpx2;
	string label;
	GraphicsInfo GI;
	GI.x1 = 0; GI.y1 = 0;
	for (int i = 0; i < Ccount; i++)
	{
		Component* entered;
		in >> componentType;
		/*in>>idnumber;
		in>>label;
		in>>tmpx1>>tmpx2;
		GI.x1 = tmpx1;
		GI.y1 = tmpx2;
		GI.x2 = tmpx1 + 50;
		GI.y2 = tmpx2 + 50;*/
		if (componentType == "AND2")
		{
			entered = new AND2(GI, 5);
		}
		else if (componentType == "AND3")
		{
			entered = new AND3(GI, 5);
		}
		else if (componentType == "NAND2")
		{
			entered = new NAND2(GI, 5);
		}
		else if (componentType == "LED")
		{
			entered = new LED(GI, 5);
		}
		else if (componentType == "INV")
		{
			entered = new INV(GI, 5);
		}
		else if (componentType == "XOR2")
		{
			entered = new XOR2(GI, 5);
		}
		else if (componentType == "XNOR2")
		{
			entered = new XNOR2(GI, 5);
		}
		else if (componentType == "Switch")
		{
			entered = new Switch(GI, 5);
		}
		else if (componentType == "OR2")
		{
			entered = new OR2(GI, 5);
		}
		else if (componentType == "NOR3")
		{
			entered = new NOR3(GI, 5);
		}
		else if (componentType == "NOR2")
		{
			entered = new NOR3(GI, 5);
		}


		entered->load(in);

		AddComponent(entered);
	}
	in >> componentType; // Connection word
	int srcCompo, DstCompo, pinindex;
	in >> srcCompo;
	InputPin* inpin;
	OutputPin* outpin;
	GraphicsInfo GI2;
	while (srcCompo != -1)
	{
		in >> DstCompo >> pinindex;
		for (int i = 0; i < CompCount; i++)
		{
			if (CompList[i]->getID() == srcCompo)
			{
				outpin=CompList[i]->getOutputPin();
				Gate* gate = dynamic_cast<Gate*>(CompList[i]);
				gate->getOutputPinCoordinates(GI2);
			}
			if (CompList[i]->getID() == DstCompo)
			{
				inpin=CompList[i]->getInputPin(pinindex);
				Gate* gate = dynamic_cast<Gate*>(CompList[i]);
				gate->getPinCoordinates(pinindex, GI2);

			}
		}
		Component* c = new Connection(GI2, outpin, inpin);
		AddComponent(c);
		in >> srcCompo;
	}

	
}



void ApplicationManager::OperateCircuit()
{
	int operatedCount = 0;
	int numberofoperation = CompCount - getnumberofConnections();
	while (operatedCount < numberofoperation)
	{
		for (int i = 0; i < CompCount; i++)
		{
			Gate* gPtr = dynamic_cast<Gate*>(CompList[i]);
			if (gPtr)
			{
				if (gPtr->checkisReady() && !gPtr->getHasOperated())
				{
					gPtr->Operate();
					gPtr->setHasOperated(true);
					operatedCount++;
				}
			}

		}
	}
		
	UpdateInterface();

	for (int i = 0; i < numberofoperation; i++)
	{
		Gate* G = dynamic_cast<Gate*>(CompList[i]);
		G->setInputsReady(0);
		G->setHasOperated(false);
	}
}
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}