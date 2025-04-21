#include "BaseField.h"

BaseField::BaseField(sf::Vector2f location)
    :m_text(Text("",location))
{
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
