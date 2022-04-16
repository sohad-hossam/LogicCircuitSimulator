#pragma once
#ifndef _Delete_GATE_H
#define _Delete_GATE_H


#include "Actions/Action.h"

class Delete :public Action
{
private:
	int x, y;   //The point where the user clicks
public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
#endif
