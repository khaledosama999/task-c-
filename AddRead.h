#pragma once
#include"Actions/Action.h"
class AddRead:public Action
{
private:
	Point Position;
	string Variable;
public:
	AddRead(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();

	virtual void Execute();
};

