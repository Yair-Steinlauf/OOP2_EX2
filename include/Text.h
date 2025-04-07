#pragma once
#include <SFML/Graphics.hpp>
#include "MainObject.h"

class Text : public MainObject {
public:
	Text(std::string text = "", sf::Color color = sf::Color::Black, sf::Text::Style style = sf::Text::Bold
		, unsigned int characterSize = 24, sf::Font font = sf::Font(),
		sf::Vector2f location = sf::Vector2f(0, 0));

	
};