#pragma once
#include <string>

class YesNoValidator {
public:
	static bool validate(const std::string& field);
	static std::string getError();
};