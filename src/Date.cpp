#include "Date.h"

int Date::getDay() const
{
	return m_day;
}

int Date::getMonth() const
{
	return m_month;
}

int Date::getYear() const
{
	return m_year;
}

Date::Date(int day, int month, int year)
{
	m_day = day;
	m_month = month;
	m_year = year;
}
Date::Date(const Date& other)
{
	*this = other;
}

Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		m_day = other.m_day;
		m_month = other.m_month;
		m_year = other.m_year;
	}
	return *this;
}
bool Date::operator==(const Date& other) const
{
	return (m_day == other.m_day && m_month == other.m_month && m_year == other.m_year);
}
bool Date::operator!=(const Date& other) const
{
	return !(*this == other);
}
std::istream& operator>>(std::istream& is, Date& date)
{
	int day, month, year;
	char sep1, sep2;

	
	if (is >> day >> sep1 >> month >> sep2 >> year)
	{
		if (sep1 == '-' && sep2 == '-') {
			date = Date(day, month, year); 
		}
		else {
			is.setstate(std::ios::failbit); 
		}
	}
	return is;
}
std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
	return os;
}