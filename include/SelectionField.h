#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"
#include "Field.h"
#include "SelectionButton.h"
#include "vector"
#include "memory"
class SelectionField {
private:
	std::unique_ptr<BaseField> m_field;
	std::vector<std::unique_ptr<SelectionButton>> m_buttons;
public:
	SelectionField(std::unique_ptr<BaseField> field , std::vector<std::unique_ptr<SelectionButton>> buttons);
	SelectionField();
	void update(const sf::Time& time);
	bool contains(sf::Vector2f& coords);
	void draw(sf::RenderWindow& window);
	void handleEvent(sf::Event& event);

};