#pragma once

#ifndef _Cut_H
#define _Cut_H

#include "Actions/Action.h"
#include"ApplicationManager.h"
#include "Copy.h"
class Cut :public Action
{
	private:
		Output* pOut;
		Input* pIn;
		int x, y;	//Center point of the gate
		Copy* cpd;
	public:
		Cut(ApplicationManager* pApp);
		virtual ~Cut(void);

		//Reads parameters required for action to execute
		virtual void ReadActionParameters();
		//Execute action (code depends on action type)
		virtual void Execute();
		virtual void Undo();
		virtual void Redo();

	};
#endif



