#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "DataLoader.h"
class Text{
private:
	sf::Text m_text;
public:
	Text(std::string text = "", sf::Vector2f location = sf::Vector2f(0, 0) ,
		sf::Color color = sf::Color(60, 60, 60), sf::Text::Style style = sf::Text::Style::Regular
		, unsigned int characterSize = 18);
	void draw(sf::RenderWindow& window);
	void setText(std::string text);
	void setLocation(sf::Vector2f newLocation);
	void setFillColor(const sf::Color& color);
	sf::Text& getText();
};