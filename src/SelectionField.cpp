#include "SelectionField.h"


SelectionField::SelectionField(Text lable, BaseField field, std::vector<SelectionButton> buttons)
	:m_lable(lable), m_buttons(buttons)
{
	m_field = std::make_unique<BaseField>(field);
}

void SelectionField::update(const sf::Time& time)
{
	m_field.get()->update(time);
	for (auto& button : m_buttons)
		button.update();

}

bool SelectionField::contains(const sf::Vector2f& coords)
{
	for (auto& button : m_buttons) {
		if (button.contains(coords))
			return true;
	}
	return false;
}

void SelectionField::draw(sf::RenderWindow& window)
{
	m_field.get()->draw(window);
	for (auto& button : m_buttons)
		button.draw(window);
	m_lable.draw(window);
}

void SelectionField::handleEvent(const sf::Event& event)
{
	for (auto& button : m_buttons)
	{
		if (button.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
		{
			m_field.get()->setUserInput(button.getText());
			button.onClick();
			break;
		}
	}
}
