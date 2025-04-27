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

void BaseField::handleInput(sf::Event event)
{
    
    if (event.type == sf::Event::TextEntered) {
        std::cout << "is here";
        std::string text = m_text.getText().getString();
        if (event.text.unicode == '\b' && !m_text.getText().getString().isEmpty() ) {            
            text.resize(text.size() - 1);
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
            std::cout << "got: " << static_cast<char>(event.text.unicode);
            text += static_cast<char>(event.text.unicode);
        }
        m_text.setText(text);
    }

}

bool BaseField::contains(sf::Vector2f location)
{
    if (m_rect.getGlobalBounds().contains(location)) {
        return true;
    }
    return false;
}

void BaseField::draw(sf::RenderWindow& window)
{
    window.draw(m_rect);
    m_text.draw(window);
}

void BaseField::onPressClick()
{
    m_isClicked = true;    
    m_rect.setOutlineColor(sf::Color(0, 120, 255));
// TODO cursur
}

void BaseField::onReleaseClick()
{
    m_isClicked = false;
    m_rect.setOutlineColor(sf::Color(160, 160, 160));
}
