#pragma once
#include "Text.h"

class Button{
protected:
	Text m_text;
	sf::RectangleShape m_rectangle;
	bool m_isClicked = false;
public:
	Button(const Text& text = Text());
	virtual bool contains(const sf::Vector2f& coords);
	void draw(sf::RenderWindow& window);
	std::string getText() const;
	virtual void onClick();
	virtual void update() = 0;
	~Button() = default;
};

