#include "Address.h"
#include <string>

std::string Address::getCity() const
{
	return m_city;
}

std::string Address::getStreet() const
{
	return m_street;
}

int Address::getNumber() const
{
	return m_number;
}



Address::Address(std::string street, std::string city, int number)
{
	m_street = street;
	m_city = city;
	m_number = number;
}

Address::Address(const Address& other)
{
	*this = other;
}

Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		m_street = other.m_street;
		m_city = other.m_city;
		m_number = other.m_number;
	}
	return *this;
}
std::istream& operator>>(std::istream& is, Address& address)
{
	std::string street, city;
	int number;
	std::string line;
	is >> line;
	
	size_t firstDash = line.find('-');
	size_t secondDash = line.find('-', firstDash + 1);

	if (firstDash != std::string::npos && secondDash != std::string::npos) {
		street = line.substr(0, firstDash);
		number = std::stoi(line.substr(firstDash + 1, secondDash - firstDash - 1));
		city = line.substr(secondDash + 1);
	}
	address = Address(street, city, number);
	return is;
}
std::ostream& operator<<(std::ostream& os, const Address& address)
{
	os << address.getStreet() << ", " <<  address.getNumber() << ", " << address.getCity() ;
	return os;
}
bool Address::operator==(const Address& other) const
{
	return (m_street == other.m_street && m_city == other.m_city && m_number == other.m_number);
}

bool Address::operator!=(const Address& other) const
{
	return !(*this == other);
}
