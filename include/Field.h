#pragma once
#include "BaseField.h"
#include "BaseValidator.h"
#include <sstream>
#include <iostream>



template<typename Validator, typename Type>
class Field : public BaseField {
private:
	Type m_data;
	Validator m_validator;
public:
	Field(Type data  = Type(), sf::Vector2f location = sf::Vector2f(0, 0))
	: BaseField(location) {
		
	}

	std::string getError();
};

template<typename Validator, typename Type>
inline std::string Field<Validator, Type>::getError()
{
	std::string fieldText = m_text.getString();
	
	std::istringstream iss(fieldText);
	iss >> m_data;
	if (Validator::validate(m_data))
		return "";
	return Validator::getError();
}
