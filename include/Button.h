#pragma once
#include "Text.h"

class Button{
protected:
	Text m_text;
	sf::RectangleShape m_rectangle;
	bool m_isClicked = false;
public:
	Button(const Text& text = Text());
	virtual bool contains(sf::Vector2f& coords);
	void draw(sf::RenderWindow& window);
	virtual void onClick();
	virtual void update() = 0;
	~Button() = default;
};

