#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	CreateStatusBar();		//Create Status bar
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (design) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(UI.ToolBarHeight, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
void Output::ClearDesignToolbar() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(WHITE);
	for (int i = 0; i < ITM_DSN_CNT - 10; i++)
	{
		pWind->DrawRectangle(i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}
	int count = 1;
	for (int i = ITM_DSN_CNT - 10; i < ITM_DSN_CNT; i++)
	{
		pWind->DrawRectangle(0, count * UI.ToolItemWidth, UI.ToolItemWidth, UI.ToolBarHeight);
		count++;
	}
	pWind->SetPen(WHITE);
	pWind->DrawLine(UI.ToolBarHeight, 50, UI.ToolBarHeight, UI.width);
}
void Output::ClearSimulationbar() const
{
	for (int i = 0; i < ITM_SIM_CNT; i++)
	{
		pWind->DrawRectangle(i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpeg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpeg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpeg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpeg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpeg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpeg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpeg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpeg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpeg";
	MenuItemImages[ITM_Buff] = "images\\Menu\\Menu_Buffer.jpeg";
	MenuItemImages[ITM_INV] = "images\\Menu\\Menu_NOT.jpeg";
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_Switch.jpeg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpeg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\Menu_Connection.jpeg";
	MenuItemImages[ITM_SM] = "images\\Menu\\Menu_SwitchMode.jpeg";
	MenuItemImages[ITM_Label] = "images\\Menu\\Menu_Label.jpeg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_Save.jpeg";
	MenuItemImages[ITM_Copy] = "images\\Menu\\Menu_Copy.jpeg";
	MenuItemImages[ITM_Cut] = "images\\Menu\\Menu_Cut.jpeg";
	MenuItemImages[ITM_Paste] = "images\\Menu\\Menu_Paste.jpeg";
	MenuItemImages[ITM_SELECT] = "images\\Menu\\Menu_Select.jpeg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_Load.jpeg";
	MenuItemImages[ITM_DEL] = "images\\Menu\\Menu_Delete.jpeg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\Menu_EditLabel.jpeg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpeg";
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT - 10; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}
	int count = 1;
	for (int i = ITM_DSN_CNT - 10; i < ITM_DSN_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], 0, count * UI.ToolItemWidth, UI.ToolItemWidth, UI.ToolBarHeight);
		count++;
	}
	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	//line next to the side toolbar
	pWind->DrawLine(UI.ToolBarHeight, 50, UI.ToolBarHeight, UI.width);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_SIM] = "images\\Menu\\Menu_simulate.jpeg";

	int count = 1;
	for (int i = 0; i < ITM_SIM_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		count++;
	}
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}


//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawInv(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOT_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_NOT.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::Drawswitch(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Switch_OFF_HI.jpeg";
	else
		GateImage = "Images\\Gates\\Switch_OFF.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawswitchON(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Switch_ON_HI.jpeg";
	else
		GateImage = "Images\\Gates\\Switch_ON.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawBuffer(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\BUFFER_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\BUFFER.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_NAND.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
		if (selected)	//use image in the highlighted case
			GateImage = "Images\\Gates\\LED_OFF_HI.jpeg";
		else
			GateImage = "Images\\Gates\\LED_OFF.jpeg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawLEDON(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED_ON_HI.jpeg";
	else
		GateImage = "Images\\Gates\\LED_ON.jpeg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpeg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	if (selected)
	{
		pWind->SetPen(BLUE);
		if (r_GfxInfo.y1 == r_GfxInfo.y2)

			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);

		else if (r_GfxInfo.x1 == r_GfxInfo.x2)

			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2);

		else
		{
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
		}

	}
	else
	{
		pWind->SetPen(BLACK);
		if (r_GfxInfo.y1 == r_GfxInfo.y2)
			
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
		
		else if (r_GfxInfo.x1 == r_GfxInfo.x2)

			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2);
		
		else
		{
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
		}

	}
}


void Output::DrawString(int x, int y, string s) const
{
	pWind->DrawString(x, y, s);
}

Output::~Output()
{
	delete pWind;
}
