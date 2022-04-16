#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	selected = 0; //default for selection
	tmpindex++;
	setID(tmpindex);
}
int Component::tmpindex = 0;

void Component::setSelected(bool s)
{
	selected = s;
}

bool Component::getSelected()
{
	return selected;
}

void Component::setLabel(string str)
{
	m_Label = str;
}

string Component::getLabel()
{
	return m_Label;
}

void Component::setGraphicsInfo(GraphicsInfo x)
{
	m_GfxInfo.x1 = x.x1;
	m_GfxInfo.x2 = x.x2;
	m_GfxInfo.y1 = x.y1;
	m_GfxInfo.y2 = x.y2;
}

GraphicsInfo Component::getinfo()
{
	return m_GfxInfo;
}
Component::Component()
{}

int Component::getID()
{
	return ID;
}

void Component::setID(int tmpindex)
{
	ID = tmpindex;
}

void Component::SetOperateNow(bool b)
{
	operatenow = b;
}

Component::~Component()
{}

