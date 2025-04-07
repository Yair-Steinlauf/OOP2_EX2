#pragma once
#include <SFML/Graphics.hpp>
class MainObject{
protected:
	sf::Text m_text;
	MainObject(std::string text,sf::Color color, sf::Text::Style style = sf::Text::Bold
		,unsigned int characterSize, sf::Font font,
		sf::Vector2f location);
public:
	virtual void draw(sf::RenderWindow& window);
};
class Text : public MainObject {
public:
	Text(sf::Color color, sf::Text::Style style, sf::Vector2f location);
};

class Button : public MainObject {
private:
	sf::RectangleShape& m_rectangle;
public:
	Button(Text& text, sf::Vector2f size,sf::Color fillColor, sf::Vector2f location);

};
class BaseField : public Button{
protected:
	bool isClicked = false;
public:
	BaseField(Button& button);
	
};

template<typename T>
class Field : public BaseField {
private:
	T m_data;
public:
	//default validator
	bool validate() {
		return true;
	}
};
struct Name {
	std::string name;
};

struct Date{};
template<>
bool Field<Name>::validate() {
	for (int index = 0; index < m_data.name.length(); index++)
		if (isdigit(m_data.name[index])) return false;
	return true;
}

template<>
bool Field<Date>::validate() {

}
//bool validor<Date>() {
//	//date validation;
//}
//bool validor<std::string>() {
//	//no number validation;
//}

