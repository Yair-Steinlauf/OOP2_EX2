#pragma once
#include <string>
class RentTotalDayValidator {
public:
	static bool validate(const int& days);
	static std::string getError();

};