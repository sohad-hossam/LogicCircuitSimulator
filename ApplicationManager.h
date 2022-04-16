#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Switch.h"
#include "Components\Gate.h"
#include <fstream>
using namespace std;

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface

	Component* CpdComp;// pointer to the copied comp
	int indicator; // indicates wether object is copied or cut
public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	OutputPin* checkOutputPinClick(float x, float y, GraphicsInfo& pinGfxInfo);//check if user clicked on outputpin 
	InputPin* checkInputPinClick(float x, float y, GraphicsInfo& pinGfxInfo); //Check if user clicked on input pin
	Component* InsideArea(float x, float y); //returns the component where the point was clicked
	void DeleteComponent(float x, float y);
	void ShiftCompList(int i);
	void setCpdComp(Component* s);// setter for copied component
	Component* getCpdComp();
	void setindicator(int s);
	int getindicator();
	void DeletegateConnections(Gate* gPtr);
	Component* getGateFromOutputPin(OutputPin* OP);
	void SaveAll(ofstream &out);
	void load(ifstream& in);
	void OperateCircuit();
	int getnumberofConnections();
	bool CheckFloatingPins();
	~ApplicationManager();
};

#endif