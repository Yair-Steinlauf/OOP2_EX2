#pragma once
#include "Button.h"

class ConfirmationBtn : public Button
{
public:
	ConfirmationBtn(std::string text = "Done", sf::Vector2f location = sf::Vector2f(0, 0), sf::Color color = sf::Color(50, 150, 50));
	~ConfirmationBtn() = default;
	void update() override;
	void onClick() override;
private:

};
