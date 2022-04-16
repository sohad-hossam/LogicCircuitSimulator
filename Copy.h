#pragma once
#ifndef copy_H
#define copy_H


#include "Actions/Action.h"
#include"ApplicationManager.h"
class Copy :public Action
{
private:
	int x, y;//point where user clicks 
	Output* pOut;
	Input* pIn;

public:
	Copy(ApplicationManager* pApp);
	virtual ~Copy(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};
#endif;
