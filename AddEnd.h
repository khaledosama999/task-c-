#pragma once
#include"Actions/Action.h"
class AddEnd:public Action
{
private:
	Point Position;
public:
	AddEnd(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};

