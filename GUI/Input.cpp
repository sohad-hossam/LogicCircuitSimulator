//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{

	keytype kt;
	string str = "";
	int i = 0;

	char cn;
	while (1)
	{

		kt = pWind->WaitKeyPress(cn);
		if (kt == ESCAPE)
		{
			return "";
		}
		else if (kt == ASCII)
		{
			if (cn == 8)
			{
				if (str.size() > 0)
					str.resize(str.size() - 1);
				pOut->PrintMsg(str);
				continue;
			}
			if (cn == 13)
			{
				return str;
			}

			str += cn;
			pOut->PrintMsg(str);
			i++;
		}

	}


	//return NULL;
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

	return NULL;
}


string Input::editString(Output* pOut, string str)
{
	pOut->PrintMsg(str);
	keytype kts;
	char cn;
	while (1)
	{

		kts = pWind->WaitKeyPress(cn);
		if (kts == ESCAPE)
		{
			return "";
		}
		else if (kts == ASCII)
		{
			if (cn == 8)
			{
				if (str.size() > 0)
					str.resize(str.size() - 1);
				pOut->PrintMsg(str);
				continue;
			}
			if (cn == 13)
			{
				pOut->ClearStatusBar();
				return str;
			}

			str += cn;
			pOut->PrintMsg(str);
		}

	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ((y >= 0 && y < UI.ToolBarHeight))
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder1 = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder1)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_INV: return ADD_INV;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
			case ITM_Switch: return ADD_Switch;
			case ITM_Buff: return ADD_Buff;
			case ITM_CONNECTION: return ADD_CONNECTION;
			case ITM_LED: return ADD_LED;
			case ITM_SM: return SIM_MODE;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		if ((x >= 0 && x < UI.ToolBarHeight))
		{
			int ClickedItemOrder2 = ((y / UI.ToolItemWidth)+14);
			switch (ClickedItemOrder2)
			{
			case ITM_Label: return ADD_Label;
			case ITM_SAVE: return SAVE;
			case ITM_Copy: return COPY;
			case ITM_Cut: return CUT;
			case ITM_Paste: return PASTE;
			case ITM_SELECT: return SELECT;
			case ITM_LOAD: return LOAD;
			case ITM_DEL: return DEL;
			case ITM_EDIT:return EDIT;
			case ITM_EXIT: return EXIT;
			default: return DSN_TOOL; //A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
			
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if ((y >= 0 && y < UI.ToolBarHeight))
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case(ITM_SIM ): return DSN_MODE;//returns to design toolbar
			default :return SIM_MODE;
			}

		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return CHANGE_SWITCH;	//user want to select/unselect a component

		}
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}




Input::~Input()
{
}
