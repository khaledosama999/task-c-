#pragma once
#include"Statements/Statement.h"
class Start:public Statement
{
private:
	Point Center;
	Connector* pOutConn = NULL;
	Point Inlet;	
	Point Outlet;
	virtual void UpdateStatementText();
public:
	Start(Point center);
	virtual void Draw(Output* pOut) const;
};

