#include "Text.h"

Text::Text(const std::string& text, sf::Vector2f location, sf::Color color, sf::Text::Style style,
	unsigned int characterSize, sf::Font font)
	:m_text()
{
	m_text.setString(text);
	m_text.setFillColor(color);
	m_text.setStyle(style);
	m_text.setCharacterSize(characterSize);
	m_text.setFont(DataLoader::getP2Font());
	m_text.setPosition(location);
}

void Text::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
}


void Text::setText(std::string& text)
{
	m_text.setString(text);
}

std::string Text::getText() const
{
	return m_text.getString();
}

void Text::setLocation(sf::Vector2f newLocation)
{
	m_text.setPosition(newLocation);
}

void Text::setFillColor(const sf::Color& color)
{
	m_text.setFillColor(color);
}
