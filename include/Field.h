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
	Field(T& data, BaseValidator<T>* validator) {
		m_data = data;
	}
	//default validator
	bool validate() {
		m_validator->validate(m_data);
	}
	void draw(sf::RenderWindow& window) override;
};

template<typename T>
inline void Field<T>::draw(sf::RenderWindow& window)
{
	m_data.draw(window);
}
