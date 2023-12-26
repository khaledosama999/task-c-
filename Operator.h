#pragma once
#include"Statements/Statement.h"
class Operator:public Statement
{
private:
	Connector* pOutConn = NULL;
	Point Inlet;
	Point Outlet;
	Point Center;

	string Operatorr;
	string Variable;
	string RHS;
	string LHS;
	string opr;
	virtual void UpdateStatementText();
public:
	Operator(Point center, string lefths, string righths, string llhs,string operatorr);

	void setLHS(const string& L);
	void setRHS(string R);

	virtual void Draw(Output* pOut) const;
};

