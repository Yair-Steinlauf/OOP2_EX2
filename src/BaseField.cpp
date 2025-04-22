#include "BaseField.h"

BaseField::BaseField(sf::Vector2f location)
    :m_text(Text("",location))
{
	m_rect.setSize(sf::Vector2f(250, 35));
    m_rect.setPosition(location);
    m_rect.setFillColor(sf::Color::White);
    m_rect.setOutlineThickness(2);
    m_rect.setOutlineColor(sf::Color(160, 160, 160));
}

void BaseField::setLocation(sf::Vector2f newLocation)
{
    m_rect.setPosition(newLocation);
    m_text.setLocation(newLocation);
}

void BaseField::draw(sf::RenderWindow& window)
{
	m_text.draw(window);
	window.draw(m_rect);
}

bool BaseField::contains(sf::Vector2f& coords)
{
    return m_rect.getGlobalBounds().contains(coords);
}

void BaseField::update(sf::Time& time)
{
	m_text.setText(m_userInput);
	if (isClicked)
    { 
		m_rect.setFillColor(sf::Color(0, 120, 255));
        if (time.asMilliseconds() % 1000 < 500)
        {
			m_text.setText(m_userInput += "|");
        }
    }
    else
    {
        m_text.setFillColor(sf::Color(60, 60, 60));
    }
}
