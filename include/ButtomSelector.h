#pragma once
#include "Button.h"

class ButtonSelector : public Button
{
public:
	ButtonSelector(const std::string& text, sf::Vector2f location);
	~ButtonSelector() = default;
	void update();
private:

};
