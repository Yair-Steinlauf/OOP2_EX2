#pragma once
#include <string>
#include <vector>


class CarAndGpsValidator {
public:
	static bool validate(const std::vector<std::string>& data);
	static std::string getError();
};