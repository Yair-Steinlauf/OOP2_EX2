#pragma once
#include <string>

class NameValidator  {
public:
	static bool validate(const std::string& name);
	static std::string getError();
};
