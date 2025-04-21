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
		sf::Color color = sf::Color(60, 60, 60), sf::Text::Style style = sf::Text::Bold
		, unsigned int characterSize = 18, sf::Font font = DataLoader::getP2Font());
	void draw(sf::RenderWindow& window);
	void setText(std::string& text);
};