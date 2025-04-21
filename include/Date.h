#pragma once

class Date {
private:
	int m_day, m_month, m_year;
public:
	Date(int day = 1, int month = 1, int year = 2000);
	Date(const Date& other);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	Date& operator=(const Date& other);	
	bool operator==(const Date& other) const;	
	bool operator!=(const Date& other) const;
	~Date() = default;
};

std::istream& operator>>(std::istream& is, Date& date);
std::ostream& operator<<(std::ostream& os, const Date& date); 