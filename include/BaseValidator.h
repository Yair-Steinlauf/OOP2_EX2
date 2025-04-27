#pragma once
#include <string>

class AddressValidator;
class IDValidator;
class EmailValidator;
class DateValidator;

template <typename Type>


class BaseValidator {
public:
	virtual bool validate(const Type& object) const = 0;
	virtual ~BaseValidator() = default;
};

