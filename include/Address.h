#pragma once

class Address {
private:
	std::string m_street , m_city;
	int m_number;
public:
	std::string getCity() const;
	std::string getStreet() const;
	int getNumber() const;
	Address(std::string street = "", std::string city = "", int number = 0);
	Address(const Address& other);
	Address& operator=(const Address& other);
	bool operator==(const Address& other) const;
	bool operator!=(const Address& other) const;
	~Address() = default;
};
std::istream& operator>>(std::istream& is, Address& address);
std::ostream& operator<<(std::ostream& os, const Address& address);