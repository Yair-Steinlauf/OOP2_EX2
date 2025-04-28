#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"

class BaseField{
protected:
	Text m_text;
	sf::RectangleShape m_rect;
	bool m_isClicked = false;	

public:
	BaseField(sf::Vector2f location = sf::Vector2f(0,0));
	void setLocation(sf::Vector2f newLocation);
	void handleInput(sf::Event event);
	bool contains(sf::Vector2f location);
	virtual void draw(sf::RenderWindow& window);
	void onPressClick();
	void onReleaseClick();
	void setText(const std::string text);
	std::string getText();
	virtual std::string getError() = 0;
	virtual ~BaseField() = default;
};
