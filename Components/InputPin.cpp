#include "InputPin.h"

InputPin::InputPin()
{
	connected = false;
	isReady = false;
}

void InputPin::setConnected(bool s)
{
	connected = s;
}

bool InputPin::getConnected()
{
	return connected;
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::setisReady(bool b)
{
	isReady = b;
}

bool InputPin::getisReady()
{
	return isReady;
}
