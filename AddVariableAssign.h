#pragma once
#include"Actions/Action.h"
#include "Statements/Statement.h"
#include"ApplicationManager.h"

class AddVariableAssign:public Action
{
private :
	string Righths;
	string Lefths;
	Point Position;
public:
	AddVariableAssign(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();

};

