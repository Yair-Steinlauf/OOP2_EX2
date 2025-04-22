#pragma once
#include "Date.h"
#include "BaseValidator.h"

class DateValidator : public BaseValidator<Date> {
public:
	static DateValidator& getInstance() {
		static DateValidator instance;
		return instance;
	}
	bool validate(const Date& date) const;

private:
	DateValidator() = default;
	DateValidator(const DateValidator&) = delete;
	DateValidator& operator=(const DateValidator&) = delete;
	~DateValidator() = default;

	
	
};