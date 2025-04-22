#include "AddressValidator.h"
#include "NameValidator.h"
bool AddressValidator::validate(const Address& address) const
{
	bool cityValid = NameValidator::getInstance().validate(address.getCity());
	bool streetValid = NameValidator::getInstance().validate(address.getStreet());
	bool numValid = address.getNumber() > 0;
	return numValid && streetValid && cityValid;
}