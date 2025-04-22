#include "Button.h"


Button::Button(const Text& text)
	:m_text(text)
{
}

bool Button::contains(const sf::Vector2f& coords)
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

std::string Button::getText() const
{
	return m_text.getText();
}

void Button::onClick()
{
	m_isClicked = true;
}
