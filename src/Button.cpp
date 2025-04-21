#include "Button.h"

Button::Button(Text& text, sf::Vector2f size, sf::Color fillColor, sf::Vector2f location) 
	: m_text(text)
{
	m_rectangle.setSize(size);
	m_rectangle.setFillColor(fillColor);
	m_rectangle.setPosition(location);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_rectangle);
	m_text.draw(window);
}
