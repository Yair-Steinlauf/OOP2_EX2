#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"



class BaseField{
protected:
	Text m_text;
	sf::RectangleShape m_rect;
	bool m_isClicked = false;
	

public:
	BaseField(sf::Vector2f location);
	void setLocation(sf::Vector2f newLocation);
	void handleInput(sf::Event event);
	bool contains(sf::Vector2f location);
	virtual void draw(sf::RenderWindow& window);
	void onPressClick();
	void onReleaseClick();


};
