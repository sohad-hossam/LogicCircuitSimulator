#pragma once
#ifndef _LOAD
#define _LOAD

#include "Actions\Action.h"
#include <fstream>
using namespace std;

class Load : public Action
{
private:
	ifstream inputFile;
public:
	Load(ApplicationManager* pApp);
	virtual ~Load(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


#endif