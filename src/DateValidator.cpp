#include "DateValidator.h"

bool DateValidator::validate(const Date& date)
{
    if ( // check if the year is leap year. first check if the year is bigger than zero and smaller or equal to 3000.
        // the first check is if it february, check if the year is divisible to 4 and year not divisible to 100 or divisible to 400. in this case, the maximum day can be 29
        (year > 0 && year <= 3000 && day > 0) &&
        ((month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && day <= 29) ||
            // else this is regular year so check if month is february, the day is samller or equal to 28
            (month == 2 && day <= 28) ||
            // check for the month the days need to be smaller than 30
            (month == 4 || month == 6
                || month == 9 || month == 11) && day <= 30 ||
            // check for the month the days need to be smaller than 31.
            (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31))
    {
        return true;
    }
    return false;
}
