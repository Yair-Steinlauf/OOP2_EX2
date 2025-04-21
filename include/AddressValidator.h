#pragma once
#include "BaseValidator.h"
#include "Address.h"

class AddressValidator : public BaseValidator<Address> {
public:
	bool validate(const Address& address) override {		
};