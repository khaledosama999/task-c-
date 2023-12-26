#include "AddVariableAssign.h"
#include "VariableAssign.h"
AddVariableAssign::AddVariableAssign(ApplicationManager* pAppManager):Action(pAppManager){}
void AddVariableAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Variable Assigment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);

	pOut->PrintMessage("Click to enter the LHS: ");
	pIn->GetPointClicked(Point(0, 0));
	Lefths = pIn->GetVariable(pOut);

	pOut->PrintMessage("Click to enter the RHS: ");
	pIn->GetPointClicked(Point(0, 0));
	Righths = pIn->GetVariable(pOut);

	pOut->ClearStatusBar();
 }

void AddVariableAssign::Execute()
{
	ReadActionParameters();

	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	VariableAssign* pAssign = new VariableAssign(Corner, Lefths, Righths);
	
	pManager->AddStatement(pAssign);
 }