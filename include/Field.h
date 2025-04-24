#pragma once
#include "BaseField.h"
#include "BaseValidator.h"
#include "iostream"
#include "memory"
class NameValidator;
template<typename T>
class Field : public BaseField {
private:
	T m_data;
	std::unique_ptr<BaseValidator<T>> m_validator;
	BaseValidator<T>* m_validator;
public:
	Field(std::unique_ptr<BaseValidator<T>> validator) {
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
std::istream& operator>>(std::istream& in, Field<T>& me) {
	in >> me.m_data;
	return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Field<T>& me) {
	out << me.m_data;
	return out;
}

