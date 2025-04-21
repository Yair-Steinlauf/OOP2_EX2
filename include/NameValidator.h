#pragma once
#include <BaseValidator.h>


class NameValidator : public BaseValidator<std::string> {
public:
	bool validate(const std::string& name) const override;
};
