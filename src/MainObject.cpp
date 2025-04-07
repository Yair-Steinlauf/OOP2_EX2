#include "MainObject.h"

MainObject::MainObject(std::string text = "", sf::Color color = sf::Color::Black, sf::Text::Style style = sf::Text::Bold
	, unsigned int characterSize = 24, sf::Font font = sf::Font(),
	sf::Vector2f location = sf::Vector2f(0, 0))
{
	m_text.setString(text);
	m_text.setColor(color);
	m_text.setStyle(style);
	m_text.setCharacterSize(characterSize);
	m_text.setFont(font);
	m_text.setPosition(location);
}

void MainObject::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
}
