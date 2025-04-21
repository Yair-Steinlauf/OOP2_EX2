#pragma once
#include "BaseValidator.h"`
class IDValidator : public BaseValidator<int>
{
public:
	bool validate(const int& id) override;
};