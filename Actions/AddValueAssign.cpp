#include "AddValueAssign.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddValueAssign::AddValueAssign(ApplicationManager *pAppManager):Action(pAppManager) {}

void AddValueAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	//Read the (Position) parameter
	pOut->PrintMessage("Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);	

	pOut->PrintMessage("Click to enter the LHS: ");
	pIn->GetPointClicked(Point(0, 0));
	Lefths = pIn->GetVariable(pOut);

	pOut->PrintMessage("Click to enter the RHS: ");
	pIn->GetPointClicked(Point(0, 0));
	Righths = pIn->GetValue(pOut);

	pOut->ClearStatusBar();
}

void AddValueAssign::Execute()
{
	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH/2;
	Corner.y = Position.y ;
	
	ValueAssign *pAssign = new ValueAssign(Corner, Lefths, Righths);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()
	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}

