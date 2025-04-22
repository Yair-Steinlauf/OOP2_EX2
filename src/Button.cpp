#include "Button.h"


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

void Button::onClick()
{
	m_isClicked = true;
}
