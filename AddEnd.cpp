#include "AddEnd.h"
#include"ApplicationManager.h"
#include<sstream>
#include"End.h"
AddEnd::AddEnd(ApplicationManager* pAppManager) :Action(pAppManager){}
void AddEnd::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("End Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void AddEnd::Execute()
{
	ReadActionParameters();


	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	End* pAssign = new End(Corner);
	pManager->AddStatement(pAssign);
}
