#pragma once
#include "string"
class IDValidator
{
public:
	static bool validate(const uint32_t& fieldToValidate);
	static std::string getError();

	
};