#include "EmailValidator.h"
#include <regex>

bool EmailValidator::validate(const std::string& email) const
{
    std::regex emailPattern(R"(^[A-Za-z0-9.-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    return std::regex_match(email, emailPattern);
}
