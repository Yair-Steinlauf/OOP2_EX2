#pragma once
#include "BaseValidator.h"`
class IDValidator : public BaseValidator<uint32_t>
{
public:
	bool validate(const uint32_t& fieldToValidate) const override;
};