#include "IDValidator.h"



bool IDValidator::validate(const uint32_t& fieldToValidate)
{
    int sum = 0, incNum;
    uint32_t numArr[9] = { 0 };
    uint32_t tmp = fieldToValidate;

    // check the length of the number
    if (fieldToValidate < 100000000 || fieldToValidate > 999999999) {
        return false;
    }

    // convert the number to an array for easy check later
    for (int i = 8; i >= 0; i--) {
        numArr[i] = tmp % 10;
        tmp = tmp / 10;
    }

    // validate the id number
    for (int i = 0; i < 9; i++) {
        incNum = numArr[i] * ((i % 2) + 1);
        sum += (incNum > 9) ? incNum - 9 : incNum;
    }
    if (sum % 10 == 0) {
        return true;
    }

    return false;

}

std::string IDValidator::getError()
{
    return "Not valid ID";
}
