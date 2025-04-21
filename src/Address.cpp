#include "Adrress.h"
#include "Address.h"

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
	is >> address.m_street >> address.m_number >> address.m_city;
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
