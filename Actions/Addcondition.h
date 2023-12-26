#pragma once
#include"Action.h"
#include "..\Statements\Statement.h"
#include"..\ApplicationManager.h"
#include"..\Statements\Condition.h"

class Addcondition :public Action
{
private:
	Point Center;

	string Operator;

	string RHS;

	string LHS;

public:
	Addcondition(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};

