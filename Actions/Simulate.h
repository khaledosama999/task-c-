#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Statements\Statement.h"
#include "..\Connector.h"
class Simulate:public Action
{
private:

public:
	Simulate(ApplicationManager* pAppManager);
	virtual void Execute();
	virtual void ReadActionParameters();
};

