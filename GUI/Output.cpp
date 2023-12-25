#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy = 15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 45;
	UI.MenuItemWidth = 65;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");

	pWind->SetPen(RED, 3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode

	//fill the tool bar 

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\Assign.jpg";
	MenuItemImages[ITM_COND] = "images\\Condition.jpg";
	MenuItemImages[ITM_START] = "images\\start.jpeg";
	MenuItemImages[ITM_END] = "images\\end.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Save.jpg";
	MenuItemImages[ITM_VARIABLE_ASSIGN] = "images\\Assign.jpg";
	MenuItemImages[ITM_OP_ASSIGN] = "images\\Assign.jpg";
	MenuItemImages[ITM_SELECT] = "images\\select.jpg";
	MenuItemImages[ITM_DELETE] = "images\\delete.jpg";
	MenuItemImages[ITM_READ_ST] = "images\\readandwrite.jpeg";
	MenuItemImages[ITM_WRITE_ST] = "images\\readandwrite.jpeg";
	MenuItemImages[ITM_CONNECTOR] = "images\\arrow.jpg";
	MenuItemImages[ITM_COPY] = "images\\COPY.jpeg";
	MenuItemImages[ITM_PASTE] = "images\\paste.jpg";
	MenuItemImages[ITM_CUT] = "images\\cut.jpg";
	MenuItemImages[ITM_LOAD] = "images\\load.jpg";
	MenuItemImages[ITM_SWITCH_SIM_MODE] = "images\\switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Exit.jpg";


	//TODO: Prepare images for each menu item and add it to the list


	//Draw menu item one image at a time
	pWind->SetPen(RED, 2);
	for (int i = 0; i < DSN_ITM_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		pWind->DrawLine((i + 1) * UI.MenuItemWidth, 0, (i + 1) * UI.MenuItemWidth, UI.ToolBarHeight);

		//Draw a line under the toolbar
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	}

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO add code to create the simulation tool bar

	string MenuItemImages[SIM_ITM_CNT];
	MenuItemImages[ITM_VALIDATE] = "images\\validate.jpg";
	MenuItemImages[ITM_RUN] = "images\\run.jpg";
	MenuItemImages[ITM_SWITCH_DESIGN] = "images\\switch.jpg";
	MenuItemImages[ITM_CONVERT_CPP] = "images\\cpp.jpg";


	//CLEARING TOOLBAR
	pWind->SetPen(WHITE, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.MenuItemWidth * DSN_ITM_CNT, UI.ToolBarHeight);


	pWind->SetPen(RED, 2);
	for (int i = 0; i < SIM_ITM_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		pWind->DrawLine((i + 1) * UI.MenuItemWidth, 0, (i + 1) * UI.MenuItemWidth, UI.ToolBarHeight - 2); //Draw line between items
	}

	//Draw a line above the toolbar
	pWind->DrawLine(0, 0, UI.width, 0);
	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}

void Output::DrawCondtionalStat(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	int* X = new int[4];
	X[0] = Left.x;
	X[1] = X[0] + (width / 2);
	X[2] = X[0] + width;
	X[3] = X[1];
	int* Y = new int[4];
	Y[0] = Left.y;
	Y[1] = Y[0] - (height);
	Y[2] = Y[0];
	Y[3] = Y[0] + (height);
	//Draw the statement block diamond
	pWind->DrawPolygon(X, Y, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 3, Left.y, Text);
}

void Output::DrawStart(Point Left, int width, int height, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 3, Left.y + height / 4, "start");
}

void Output::DrawEnd(Point Left, int width, int height, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 3, Left.y + height / 4, "end");
}

void Output::DrawIORead(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	int* X = new int[4];
	X[0] = Left.x;
	X[1] = X[0] + width;
	X[2] = X[1] - width / 5;
	X[3] = X[2] - width;
	int* Y = new int[4];
	Y[0] = Left.y;
	Y[1] = Y[0];
	Y[2] = Y[1] + height;
	Y[3] = Y[2];
	//Draw the statement block parallelogram
	pWind->DrawPolygon(X, Y, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x, Left.y + height / 2, Text);
}

void Output::DrawIOWrite(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	int* X = new int[4];
	X[0] = Left.x;
	X[1] = X[0] + width;
	X[2] = X[1] - width / 5;
	X[3] = X[2] - width;
	int* Y = new int[4];
	Y[0] = Left.y;
	Y[1] = Y[0];
	Y[2] = Y[1] + height;
	Y[3] = Y[2];
	//Draw the statement block parallelogram
	pWind->DrawPolygon(X, Y, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x, Left.y + height / 2, Text);
}

//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them

//TODO: Add DrawConnector functionfgv

void Output::DrawConnector(Point first, Point second, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	int deltax = first.x - second.x;
	int deltay = first.y - second.y;

	//int length = sqrt(deltax ^ 2 + deltay ^ 2);
	//Draw the statement block parallelogram
	pWind->DrawLine(first.x, first.y, second.x, first.y);
	pWind->DrawLine(second.x, first.y, second.x, second.y);
	if (abs(first.y - second.y) > 0)
	{
		pWind->DrawLine(second.x, second.y, second.x - deltax / 6, second.y + deltay / 6);
		pWind->DrawLine(second.x, second.y, second.x + deltax / 6, second.y + deltay / 6);
	}
	else
	{
		pWind->DrawLine(second.x, second.y, second.x + deltax / 6, second.y - deltay / 6);
		pWind->DrawLine(second.x, second.y, second.x + deltax / 6, second.y + deltay / 6);
	}

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}