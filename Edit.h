#pragma once
#pragma once
#ifndef _editLabel
#define _editLabel

#include "Actions/action.h"
#include "Defs.H"


class Edit :public Action
{
private:
	//Parameters for the destination of the label

	//Component* c;
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;
public:
	Edit(ApplicationManager* pApp);
	virtual ~Edit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif