#include "CarAndGpsValidator.h"

bool CarAndGpsValidator::validate(const std::vector<std::string>& data)
{
	if (data[0] == "Yes") {
		if (data[1] == "Sedan" || data[1] == "SUV"
			|| data[1] == "Luxury")
			return true;
	}
	else if (data[0] == "No") {
		return true;
	}
	return false;
}

std::string CarAndGpsValidator::getError()
{
	return "You sure you ask for seat with this car type?";
}
