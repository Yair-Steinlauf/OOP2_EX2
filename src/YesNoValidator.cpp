#include "YesNoValidator.h"

bool YesNoValidator::validate(const std::string& field)
{
	return field == "Yes" || field == "No";
}

std::string YesNoValidator::getError()
{
	return "You can enter only 'Yes' or 'No'";
}
