#include "NameValidator.h"

bool NameValidator::validate(const std::string& name)
{
	for (int index = 0; index < name.length(); index++)
		if (isdigit(name[index])) return false;
	return true;
}

std::string NameValidator::getError()
{
	return "No digits Allowed";
}
