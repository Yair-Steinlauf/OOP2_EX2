#pragma once
#include "Text.h"

class Button : public Text {
private:
	sf::RectangleShape m_rectangle;
public:
	Button(Text& text, sf::Vector2f size, sf::Color fillColor, sf::Vector2f location);

};