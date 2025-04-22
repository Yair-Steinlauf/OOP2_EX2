#pragma once
#include "BaseValidator.h"
class EmailValidator : public BaseValidator<std::string> {
public:
	bool validate(const std::string& email) const override;
	static EmailValidator& getInstance() {
		static EmailValidator instance;
		return instance;
	}

private:
	EmailValidator() = default;
	EmailValidator(const EmailValidator&) = delete;
	EmailValidator& operator=(const EmailValidator&) = delete;
	~EmailValidator() = default;

};