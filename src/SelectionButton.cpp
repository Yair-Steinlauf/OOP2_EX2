#include "SelectionButton.h"

SelectionButton::SelectionButton(const std::string& text, sf::Vector2f location) : 
	Button(Text(text,sf::Vector2f(location.x + 10 , location.y +5) , sf::Color::Black , sf::Text::Regular, 16))
{
	m_rectangle.setSize(sf::Vector2f(90, 30));
	m_rectangle.setPosition(location);
	m_rectangle.setFillColor(sf::Color::White);
	m_rectangle.setOutlineThickness(2);
	m_rectangle.setOutlineColor(sf::Color(160, 160, 160));
}

void SelectionButton::setClick(bool input)
{
	m_isClicked = input;
}

void SelectionButton::update()
{ 
	if (m_isClicked)
	{
		m_rectangle.setFillColor(sf::Color(0, 120, 255));
		m_text.setFillColor(sf::Color::White);
	}
	else
	{
		m_rectangle.setFillColor(sf::Color::White);
		m_text.setFillColor(sf::Color::Black);
	}
}

void SelectionButton::onClick()
{
	//TODO
}

std::string SelectionButton::getText()
{	
	return m_text.getString();
}
