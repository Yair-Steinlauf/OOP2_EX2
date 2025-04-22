#include "Button.h"

//Button::Button(const std::string& text, 
//	unsigned int characterSize ,sf::Vector2f size)
//	: m_text(Text(text, location, sf::Color::White))
//{
//	m_rectangle.setSize(size);
//	m_rectangle.setFillColor(fillColor);
//	m_rectangle.setPosition(location);
//}

Button::Button(const Text& text)
	:m_text(text)
{
}

bool Button::contains(sf::Vector2f& coords)
{
	if (m_rectangle.getGlobalBounds().contains(coords))
		return true;
	return false;
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_rectangle);
	m_text.draw(window);
}
