#pragma once
#include"Actions/Action.h"
#include"Statements/Statement.h"
#include"ApplicationManager.h"
class AddOperatorAssign:public Action
{
private:
	Point Center;

	string Operatorr;

	string RHS;
	string Variable;
	string LHS;
public:
	AddOperatorAssign(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};

