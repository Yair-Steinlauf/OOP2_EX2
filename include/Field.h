#pragma once
#include "BaseField.h"
#include "BaseValidator.h"
class NameValidator;


template<typename Validator, typename Type>
class Field : public BaseField {
private:
	Type m_data;
public:
	Field(Type data , sf::Vector2f location = sf::Vector2f(0, 0))
	: BaseField(location){
		m_data = data;
	}



};

