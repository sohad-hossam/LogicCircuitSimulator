#pragma once
#ifndef Select_H
#define Select_H

#include "Actions/Action.h"
#include"ApplicationManager.h"
class Select :public Action
{
	private:
		int x, y;//point where user clicks 
		Output* pOut;
		Input* pIn;
	
	public:
		Select(ApplicationManager* pApp);
		virtual ~Select(void);

		//Reads parameters required for action to execute
		virtual void ReadActionParameters();
		//Execute action (code depends on action type)
		virtual void Execute();
		virtual void Undo();
		virtual void Redo();

};
#endif

