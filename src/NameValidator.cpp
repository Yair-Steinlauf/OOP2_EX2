#include "NameValidator.h"

bool NameValidator::validate(const std::string& name)
{
	for (int index = 0; index < m_data.name.length(); index++)
		if (isdigit(m_data.name[index])) return false;
	return true;
}
