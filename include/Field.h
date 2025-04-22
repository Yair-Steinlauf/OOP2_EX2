#pragma once
#include "BaseField.h"
#include "BaseValidator.h"
class NameValidator;
template<typename T>
class Field : public BaseField {
private:
	T m_data;
	BaseValidator<T>* m_validator;
public:
	Field(T data, BaseValidator<T>* validator) {
		m_data = data;
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

