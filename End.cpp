#include "End.h"

End::End(Point center)
{
	UpdateStatementText();
	Center = center;

	pOutConn = NULL;	//No connectors yet
	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;
	Inlet.x = Center.x;
	Inlet.y = Center.y + UI.ASSGN_HI / 2;
}
void End::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawEnd(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Selected);

}
void End::UpdateStatementText()
{
	Text = "End";
}