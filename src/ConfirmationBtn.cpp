#include "ConfirmationBtn.h"


ConfirmationBtn::ConfirmationBtn(std::string text, sf::Vector2f location, sf::Color color)
	: Button(Text(text, sf::Vector2f(location.x + 30, location.y + 10), sf::Color::White, sf::Text::Regular, 20))
{
	m_rectangle.setSize(sf::Vector2f(140, 40));
	m_rectangle.setPosition(location);
	m_rectangle.setFillColor(color);
}

void ConfirmationBtn::update()
{

}

void ConfirmationBtn::onClick()
{
}
