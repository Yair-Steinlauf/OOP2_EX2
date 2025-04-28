#pragma once

#include "Address.h"

class AddressValidator {
public:
	static bool validate(const Address& address);
	static std::string getError();
};