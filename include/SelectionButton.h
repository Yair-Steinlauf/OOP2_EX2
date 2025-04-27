#pragma once
#include "Button.h"

class SelectionButton : public Button
{
public:
	SelectionButton(const std::string& text, sf::Vector2f location);
	void setClick(bool input) ;
	~SelectionButton() = default;
	void update();
	void onClick();
	std::string getText();
private:

};
