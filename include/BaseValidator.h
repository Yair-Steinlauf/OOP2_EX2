#pragma once
#include <string>
template <typename T>
class BaseValidator {
public:
	virtual bool validate(const T& object) const = 0;
	virtual ~BaseValidator() = default;
};

