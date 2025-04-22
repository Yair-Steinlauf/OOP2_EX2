#pragma once
#include "Button.h"

class ConfirmationButton : public Button
{
public:
	ConfirmationButton(const std::string& text, sf::Vector2f location, sf::Color color);
	~ConfirmationButton() = default;
	void update();
private:

};
