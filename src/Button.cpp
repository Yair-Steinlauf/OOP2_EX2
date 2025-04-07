#include "Button.h"

Button::Button(Text& text, sf::Vector2f size, sf::Color fillColor, sf::Vector2f location) 
	: Text(text)
{
	m_rectangle.setSize(size);
	m_rectangle.setFillColor(fillColor);
	m_rectangle.setPosition(location);

}