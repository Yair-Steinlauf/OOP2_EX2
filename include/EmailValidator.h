#pragma once
#include "string"
class EmailValidator {
public:
	static bool validate(const std::string& email) ;
	static std::string getError();

};