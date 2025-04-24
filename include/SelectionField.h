#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"
#include "Field.h"
#include "SelectionButton.h"
#include "vector"
#include "memory"
class SelectionField : public Field<std::string> {
private:
	std::vector<SelectionButton> m_buttons;
public:
	SelectionField(std::vector<SelectionButton> buttons);
	void update(const sf::Time& time);
	bool contains(const sf::Vector2f& coords);
	void draw(sf::RenderWindow& window);
	void handleEvent(const sf::Event& event);

};