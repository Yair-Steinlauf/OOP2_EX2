#include "RentTotalDayValidator.h"

bool RentTotalDayValidator::validate(const int& days)
{
	return days > 0 && days < 1000;
}

std::string RentTotalDayValidator::getError()
{
	return "Your day is not between 1 to 999. please do it correct!";
}
