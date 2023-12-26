#pragma once
#include"Actions/Action.h"
class Addwrite:public Action
{
private:
	Point Position;
	string Variable;
public:
	Addwrite(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();


	virtual void Execute();
};

