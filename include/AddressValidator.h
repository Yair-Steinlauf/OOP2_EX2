#pragma once
#include "BaseValidator.h"
#include "Address.h"

class AddressValidator : public BaseValidator<Address> {
public:
	bool validate(const Address& address) const override;
	static AddressValidator& getInstance() {
		static AddressValidator instance;
		return instance;
	}
private:
	AddressValidator() = default;
	AddressValidator(const AddressValidator&) = delete;
	AddressValidator& operator=(const AddressValidator&) = delete;
	~AddressValidator() = default;

};