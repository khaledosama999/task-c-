#pragma once
#include "Statement.h"
class Condition : public Statement
{
private:
	Connector* pOutConn = NULL;
	Point Inlet;
	Point Outlet;
	Point Center;

	string Operator;

	string RHS;
	string LHS;
	string opr;
	
	virtual void UpdateStatementText();

public:
	Condition(Point center, string lefths, string righths, string operatorr);

	void setLHS(const string& L);
	void setRHS(string R);

	virtual void Draw(Output* pOut) const;

};

