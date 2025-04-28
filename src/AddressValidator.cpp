#include "AddressValidator.h"
#include "NameValidator.h"


bool AddressValidator::validate(const Address& address)
{
	bool isCityValid = NameValidator::validate(address.getCity());
	bool isStreetValid = NameValidator::validate(address.getStreet());
	bool isNumberValid = address.getNumber() > 0;
	return isNumberValid && isStreetValid && isCityValid;
}

std::string AddressValidator::getError()
{
	return "Adress not valid";
}
