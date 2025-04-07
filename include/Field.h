#pragma once
#include "BaseField.h"

template<typename T>
class Field : public BaseField {
private:
	T m_data;
public:
	Field(T& data) {
		m_data = data;
	}
	//default validator
	bool validate() {
		return true;
	}
};
struct Name {
	std::string name;
};

struct Date {};
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

