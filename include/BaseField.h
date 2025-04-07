#pragma once
#include "Button.h"




class BaseField : public Button{
protected:
	bool isClicked = false;
public:
	BaseField(Button& button);
	
};
