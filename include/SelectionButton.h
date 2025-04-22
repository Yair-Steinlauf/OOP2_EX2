#pragma once
#include "Button.h"

class SelectionButton : public Button
{
public:
	SelectionButton(const std::string& text, sf::Vector2f location, sf::Vector2f size = sf::Vector2f(90, 30));
	~SelectionButton() = default;
	void update();
private:

};
