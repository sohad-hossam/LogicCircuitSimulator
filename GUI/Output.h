#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void ClearDesignToolbar() const;//clears the area where the Design toolbar was
	void ClearSimulationbar() const;// clears the sim bar after switching to design mode
	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window


	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawInv(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawswitch(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawBuffer(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLEDON(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawswitchON(GraphicsInfo r_GfxInfo, bool selected) const;
	//TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc

	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void PrintMsg(string msg) const;	//Print a message on Status bar

	void DrawString(int x, int y, string s) const;
	~Output();
};
