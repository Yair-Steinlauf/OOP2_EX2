#pragma once
#include "Date.h"
#include "BaseValidator.h"

class DateValidator : public BaseValidator<Date> {
public:
	bool validate(const Date& date) const;
};