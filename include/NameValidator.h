#pragma once
#include <BaseValidator.h>


class NameValidator : public BaseValidator<std::string> {
private:
	NameValidator() = default;
	NameValidator(const NameValidator&) = delete;
	NameValidator& operator=(const NameValidator&) = delete;
	~NameValidator() = default;
public:
	static NameValidator& getInstance() {
		static NameValidator instance;
		return instance;
	}
	bool validate(const std::string& name) const override;
};
