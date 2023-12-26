#include "AddOperatorAssign.h"
#include"Operator.h"
AddOperatorAssign::AddOperatorAssign(ApplicationManager* pAppManager):Action(pAppManager){}
void AddOperatorAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Operator Assigment Statement: Click to add the statement");

	pIn->GetPointClicked(Center);

	pOut->PrintMessage("Click to enter, the variable name: ");
	pIn->GetPointClicked(Point(0, 0));
	Variable = pIn->GetVariable(pOut);

	string str;
	OpType strType;

	pOut->PrintMessage("Please enter the left hand side:");
	while (true)
	{
		str = pIn->GetString(pOut);
		strType = ValueOrVariable(str);
		if (strType == VALUE_OP || strType == VARIABLE_OP)
		{
			LHS = str;
		}
		else
		{
			pOut->PrintMessage("Error! enter the LHS of the arith operator:");
			continue;
		}
		break;

	}
	Operatorr = pIn->GetArithOperator(pOut);

	pOut->PrintMessage("Please enter the right hand side:");

	while (true)
	{
		str = pIn->GetString(pOut);
		strType = ValueOrVariable(str);
		if (strType == VALUE_OP || strType == VARIABLE_OP)
		{
			RHS = str;
		}
		else
		{
			pOut->PrintMessage("Error enter the RHS of the arith operator:");
			continue;
		}
		break;
	}

	pOut->ClearStatusBar();

 }
void AddOperatorAssign ::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Center.x - UI.ASSGN_WDTH / 2;
	Corner.y = Center.y;

	Operator* pAssign = new Operator(Corner, LHS, RHS, Variable, Operatorr);
	
	pManager->AddStatement(pAssign); 
}