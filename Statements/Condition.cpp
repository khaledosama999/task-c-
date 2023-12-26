#include "Condition.h"
#include <sstream>

Condition::Condition(Point center, string lefths, string righths, string operatorr)
{
	LHS = lefths;
	RHS = righths;
	opr = operatorr;

	UpdateStatementText();
	Center = center;

	pOutConn = NULL;	//No connectors yet
	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;
	Inlet.x = center.x;
	Inlet.y = Center.y + UI.ASSGN_HI / 2;

}
void Condition::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void Condition::setRHS(string R)
{
	RHS = R;
	UpdateStatementText();
}
void Condition::Draw(Output* pOut) const
{

	pOut->DrawCondtionalStat(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}
void Condition::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " " << opr << " " << RHS;
	Text = T.str();
}