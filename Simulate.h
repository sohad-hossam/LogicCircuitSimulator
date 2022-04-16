#pragma once
#pragma once
#ifndef _Simulate
#define _Simulate

#include "Actions/action.h"
#include "Defs.H"


class Simulate :public Action
{
private:
	int Cx, Cy;

public:
	Simulate(ApplicationManager* pApp);
	virtual ~Simulate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};

#endif