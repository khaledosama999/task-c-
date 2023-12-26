#include "Operator.h"
#include<sstream>
Operator::Operator(Point center, string lefths, string righths, string llhs, string operatorr)
{
	LHS = lefths;
	RHS = righths;
	opr = operatorr;
	Variable = llhs;

	UpdateStatementText();
	Center = center;

	pOutConn = NULL;	//No connectors yet
	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;
	Inlet.x = center.x;
	Inlet.y = Center.y + UI.ASSGN_HI / 2;

}
void Operator::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void Operator::setRHS(string R)
{
	RHS = R;
	UpdateStatementText();
}
void Operator::Draw(Output* pOut) const
{

	pOut->DrawAssign(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}
void Operator::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << Variable <<" = "<<LHS<< opr << RHS;
	Text = T.str();
}