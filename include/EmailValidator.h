#pragma once
#include "BaseValidator.h"
class EmailValidator : public BaseValidator<std::string> {
public:
	bool validate(const std::string& email) const override;

};