#pragma once
#include "Date.h"


class DateValidator {
public:
	static bool validate(const Date& date) ;
	static std::string getError();

};