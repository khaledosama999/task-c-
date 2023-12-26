#pragma once
#include"Statements/Condition.h"
class VariableAssign:public Statement
{
private:
	string LHS;	
	string RHS;	

	Connector* pOutConn = NULL;	

	Point Inlet;	
	Point Outlet;	

	Point Center;

	virtual void UpdateStatementText();
public:
	VariableAssign(Point center, string lefths, string righths);

	void setLHS(const string& L);
	void setRHS(string R);

	virtual void Draw(Output* pOut) const;

};

