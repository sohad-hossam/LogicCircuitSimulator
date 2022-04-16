#pragma once
#ifndef _ADD_Connection_GATE_H
#define _ADD_Connection_GATE_H


#include "Actions/Action.h"
#include"Components/Connection.h"
class AddConnection :public Action
{
private:
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
#endif
