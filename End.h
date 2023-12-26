#pragma once
#include"Statements/Statement.h"
class End:public Statement
{
private:
	Point Center;
	Connector* pOutConn = NULL;
	Point Inlet;
	Point Outlet;
	virtual void UpdateStatementText();
public:
	End(Point center);
	virtual void Draw(Output* pOut) const;
};

