#pragma once
#include "Text.h"

class Button{
private:
	Text m_text;
	sf::RectangleShape m_rectangle;
public:
	Button(Text& text, sf::Vector2f size, sf::Color fillColor, sf::Vector2f location);
	void draw(sf::RenderWindow& window);

};