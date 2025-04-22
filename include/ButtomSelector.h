#pragma once
#include "Button.h"

class ButtonSelector : public Button
{
public:
	ButtonSelector(const std::string& text, sf::Vector2f location);
	void onClick() override;
	~ButtonSelector() = default;
	void update();
private:

};
