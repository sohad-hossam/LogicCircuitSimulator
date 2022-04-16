#pragma once
#ifndef _paste_H
#define _paste_H


#include "Actions/Action.h"
#include"ApplicationManager.h"

class Paste :public Action
{
private:
	Output* pOut;
	Input* pIn;
	int Cx, Cy;	//Center point of the gate
	//int x1, y1, x2, y2;	//Two corners of the rectangluar area

public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};
#endif
