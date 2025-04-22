#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"
#include "Field.h"
#include "SelectionButton.h"
#include "vector"
#include "memory"
class SelectionField {
private:
	Text m_lable;
	std::unique_ptr<BaseField> m_field;
	std::vector<SelectionButton> m_buttons;
public:
	SelectionField(Text lable, BaseField field,std::vector<SelectionButton> buttons);
	void update(const sf::Time& time);
	bool contains(const sf::Vector2f& coords);
	void draw(sf::RenderWindow& window);
	void handleEvent(const sf::Event& event);

};