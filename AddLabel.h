#pragma once
#ifndef _Label
#define _Label

#include "Actions/action.h"
#include "Defs.H"


class AddLabel :public Action
{
private:
	//Parameters for the destination of the label

	//Component* c;
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddLabel(ApplicationManager* pApp);
	virtual ~AddLabel(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif