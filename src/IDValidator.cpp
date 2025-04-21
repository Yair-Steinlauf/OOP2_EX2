#include "IDValidator.h"

bool IDValidator::validate(const int& id)
{
    if (id < 100000000 || id > 999999999) {
        return false; // Ensure it's 9 digits
    }

    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int digit = id % 10;
        int incNum = digit * ((8 - i) % 2 + 1); // נתחיל מימין לשמאל
        if (incNum > 9) incNum -= 9;
        sum += incNum;
        id /= 10;
    }

    return (sum % 10 == 0);
}
