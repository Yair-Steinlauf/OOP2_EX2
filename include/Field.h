#pragma once
#include "BaseField.h"
#include "BaseValidator.h"
#include "istream"

class NameValidator;
template<typename T>
class Field : public BaseField {
private:
	T m_data;
	BaseValidator<T>* m_validator;
public:
	Field(BaseValidator<T>* validator) {
		m_validator = validator;
	}
	//default validator
	bool validate() {
		m_validator->validate(m_data);
	}
	void draw(sf::RenderWindow& window) override {
		window.draw(m_rect);
		m_text.draw(window);
	}
};


template <typename T>
std::istream& operator>>(std::istream& in, T& data) {
	in >> data;
	return in;
}

