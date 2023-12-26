#include "Addstart.h"
#include"ApplicationManager.h"
#include <sstream>
#include"Start.h"
Addstart::Addstart(ApplicationManager* pAppManager):Action(pAppManager) {}
void Addstart::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Start Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void Addstart::Execute()
{
	ReadActionParameters();

	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Start* pAssign = new Start(Corner);
	pManager->AddStatement(pAssign); 
}

