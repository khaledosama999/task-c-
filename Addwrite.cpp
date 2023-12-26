#include "Addwrite.h"
#include"ApplicationManager.h"
#include<sstream>
#include"Write.h"
Addwrite::Addwrite(ApplicationManager* pAppManager):Action(pAppManager){}
void Addwrite::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("Write Statement: Click to add the statement");

	pIn->GetPointClicked(Position);

	pOut->PrintMessage("Click to enter the variable name: ");
	pIn->GetPointClicked(Point(0, 0));
	Variable = pIn->GetVariable(pOut);

	pOut->ClearStatusBar();
}
void Addwrite::Execute()
{
	ReadActionParameters();

	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Write* pAssign = new Write(Corner, Variable);
	pManager->AddStatement(pAssign);


}
