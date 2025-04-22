#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"



class BaseField{
protected:
	Text m_text;
	std::string m_userInput;
	sf::RectangleShape m_rect;
	bool isClicked = false;
public:
	BaseField(sf::Vector2f location = sf::Vector2f(0,0));
	void setLocation(sf::Vector2f newLocation);
	virtual void draw(sf::RenderWindow& window);
	bool contains(sf::Vector2f& coords);
	void update(sf::Time& time);
};
