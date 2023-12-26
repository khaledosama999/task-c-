#pragma once
#include"Statements/Statement.h"
class Write:public Statement
{
private:
	Point Center;
	Connector* pOutConn = NULL;
	Point Inlet;
	Point Outlet;
	string Variable;
	virtual void UpdateStatementText();
public:
	Write(Point center, string variable = "");
	virtual void Draw(Output* pOut) const;
	void SetVariable(const string& variable);
};

