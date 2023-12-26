#include "AddRead.h"
#include"ApplicationManager.h"
#include<sstream>
#include"Read.h"
AddRead::AddRead(ApplicationManager* pAppManager) :Action(pAppManager) {}
void AddRead::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Read Statement: Click to add the statement");

	pIn->GetPointClicked(Position);

	pOut->PrintMessage("Click to enter the variable name: ");
	pIn->GetPointClicked(Point(0, 0));
	Variable = pIn->GetVariable(pOut);

	pOut->ClearStatusBar();
}


void AddRead::Execute()
{
	ReadActionParameters();


	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Read* pAssign = new Read(Corner, Variable);

	pManager->AddStatement(pAssign);
}
