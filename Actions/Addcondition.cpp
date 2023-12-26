#include"Addcondition.h"
Addcondition::Addcondition(ApplicationManager* pAppManager) :Action(pAppManager) {}

void Addcondition::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("coditional Statement: Click to add the statement");

	pIn->GetPointClicked(Center);
	pOut->PrintMessage("Please enter the left hand side:");

	string str;
	OpType strType;

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
			pOut->PrintMessage("Error! enter the LHS of the comparidon:");
			continue;
		}
		break;

	}
	
	Operator = pIn->GetCompOperator(pOut);

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
			pOut->PrintMessage("Error! enter the RHS of the comparidon:");
			continue;
		}
		break;
	}

	pOut->ClearStatusBar();
}
void Addcondition::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Center.x - UI.ASSGN_WDTH / 2;
	Corner.y = Center.y;

	Condition* pAssign = new Condition(Corner, LHS, RHS, Operator);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()
	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list

}


