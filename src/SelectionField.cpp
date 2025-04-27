#include "SelectionField.h"


SelectionField::SelectionField(std::unique_ptr<BaseField> field, std::vector<std::unique_ptr<SelectionButton>> buttons)
	:m_buttons(std::move(buttons))
{
	m_field = std::move(field);
}

SelectionField::SelectionField()
	: m_field(std::make_unique<Field<NameValidator, std::string>>("")), m_buttons()
{
}

void SelectionField::update(const sf::Time& time)
{
	for (auto& button : m_buttons)
		button.get()->update();

}

bool SelectionField::contains(sf::Vector2f& coords)
{
	for (auto& button : m_buttons) {
		if (button.get()->contains(coords))
			return true;
	}
	return false;
}

void SelectionField::draw(sf::RenderWindow& window)
{
	m_field.get()->draw(window);
	for (auto& button : m_buttons)
		button.get()->draw(window);

}

void SelectionField::handleEvent(sf::Event& event)
{
	for (auto& button : m_buttons)
	{
		sf::Vector2f loc = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
		if (button.get()->contains(loc))
		{
			m_field.get()->setText(button.get()->getText());
			button.get()->setClick(true);
			break;
		}
		else {
			button.get()->setClick(false);
		}
	}
}