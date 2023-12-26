#include "VariableAssign.h"
#include<sstream>
VariableAssign::VariableAssign(Point center, string lefths, string righths)
{
	LHS = lefths;
	RHS = righths;

	UpdateStatementText();
	Center = center;

	pOutConn = NULL;	//No connectors yet
	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;
	Inlet.x = Center.x;
	Inlet.y = Center.y + UI.ASSGN_HI / 2;
}

void VariableAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void VariableAssign::setRHS(string R)
{
	RHS = R;
	UpdateStatementText();
}
void VariableAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}

void VariableAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}