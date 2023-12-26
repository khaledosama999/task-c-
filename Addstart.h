#pragma once
#include"Actions/Action.h"

class Addstart:public Action
{
private:
	Point Position;
public:
	Addstart(ApplicationManager* pAppManager);
	
	virtual void ReadActionParameters();

	virtual void Execute();
};

