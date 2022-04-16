#pragma once
#ifndef _ChangeSwitch_H
#define _ChangeSwitch_H

#include "Actions\action.h"


class ChangeSwitch : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate

public:
	ChangeSwitch(ApplicationManager* pApp);
	virtual ~ChangeSwitch(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif