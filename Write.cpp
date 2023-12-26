#include "Write.h"
#include<sstream>
using namespace std;
Write::Write(Point center, string variable)
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
void Write::Draw(Output* pOut) const
{
	pOut->DrawIOWrite(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}
void Write::SetVariable(const string& variable)
{
	Variable = variable;
	UpdateStatementText();
}

void Write::UpdateStatementText()
{
	stringstream T;
	T << "Write " << Variable;

	Text = T.str();
}