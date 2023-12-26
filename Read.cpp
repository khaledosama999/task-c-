#include "Read.h"
#include<sstream>
using namespace std;
Read::Read(Point center, string variable)
{
	Variable = variable;
	UpdateStatementText();
	Center = center;

	pOutConn = NULL;	//No connectors yet
	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;
	Inlet.x = Center.x;
	Inlet.y = Center.y + UI.ASSGN_HI / 2;
}
void Read::Draw(Output* pOut) const
{
	pOut->DrawIORead(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

 }
void Read::SetVariable(const string& variable)
{
	Variable = variable;
	UpdateStatementText();
}

void Read::UpdateStatementText()
{
	stringstream T;
	T << "Read " << Variable;

	Text = T.str();
}