#pragma once
#include "BaseValidator.h"
class EmailValidator : public BaseValidator<std::string> {
public:
	bool validate(const stf::string& email) override;

};