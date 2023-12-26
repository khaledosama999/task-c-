#include "Start.h"
#include<sstream>
using namespace std;
Start::Start(Point center)
{
	UpdateStatementText();
	Center = center;

	pOutConn = NULL;	//No connectors yet
	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;
	Inlet.x = Center.x;
	Inlet.y = Center.y + UI.ASSGN_HI / 2;


}
void Start::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawStart(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Selected);

}
void Start::UpdateStatementText()
{
	Text = "Start";
}
