#include "ConfimationWindow.h"

ConfimationWindow::ConfimationWindow(std::string formTitle,
	std::vector<std::string> texts,
	std::vector<std::string> fields,
	std::vector<std::string> errors,
	std::vector<std::string> specialErrors
) : formTitle(formTitle)
{

	Text title("Confirm " + formTitle, sf::Vector2f(130, 20), sf::Color::Black, sf::Text::Bold, 22);
	m_texts.push_back(title);
	int yOffset = 80;
	for (int i = 0; i < texts.size(); i++)
	{
		std::string a = texts[i];
		std::string b = fields[i];
		std::string str = a + " " + b;

		Text text(str, sf::Vector2f(50, yOffset), sf::Color::Black);
		m_texts.push_back(text);
		if (errors[i] != "") {
			approved = false;
			yOffset += 30;
			Text error(errors[i], sf::Vector2f(70, yOffset), sf::Color::Red, sf::Text::Italic, 16);
			m_texts.push_back(error);
		}
		yOffset += 30;
	}
	// check last validator:
	Text formValidators("Form Validators:", sf::Vector2f(50, yOffset), sf::Color::Black);	
	m_texts.push_back(formValidators);
	yOffset += 30;
	for (int i = 0; i < specialErrors.size(); i++)
	{
		approved = false;
		Text error(specialErrors[i], sf::Vector2f(70, yOffset), sf::Color::Red, sf::Text::Italic, 16);
		m_texts.push_back(error);
		yOffset += 30;
	}
	yOffset += 40;	
	m_approve = ConfirmationBtn("APPROVE", sf::Vector2f(20, yOffset), sf::Color(50, 150, 50));
	m_cancel = ConfirmationBtn("CANCEL", sf::Vector2f(200, yOffset), sf::Color(180, 0, 0));
}


void ConfimationWindow::render()
{
	sf::RenderWindow confirmWindow(sf::VideoMode(500, 800), "Confirm " + formTitle);
	while (confirmWindow.isOpen()) {
		sf::Event event;
		while (confirmWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				confirmWindow.close();
			sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
			if (event.type == sf::Event::MouseButtonPressed) {
				// cancel clicked: 
				if (m_cancel.contains(mousePos)) {
					confirmWindow.close();
				}
				if (m_approve.contains(mousePos)) {
					if (approved)
						std::cout << formTitle << " Confirmed! Returning to main menu." << std::endl;
					confirmWindow.close();
				}
			}
		}
		confirmWindow.clear(sf::Color(240, 240, 240));
		for (auto& text : m_texts) {
			text.draw(confirmWindow);
		}
		m_cancel.draw(confirmWindow);
		m_approve.draw(confirmWindow);
		confirmWindow.display();
	}
}