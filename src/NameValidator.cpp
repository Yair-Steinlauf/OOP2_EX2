#include "NameValidator.h"

bool NameValidator::validate(const std::string& name) const
{
	for (int index = 0; index < name.length(); index++)
		if (isdigit(name[index])) return false;
	return true;
}
