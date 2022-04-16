#ifndef _Save_H
#define _Save_H

#include "Actions\Action.h"
#include <fstream>
using namespace std;

class Save: public Action
{
	private:
		ofstream outputfile;
public:
	Save(ApplicationManager *pApp);
	virtual ~Save(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


#endif