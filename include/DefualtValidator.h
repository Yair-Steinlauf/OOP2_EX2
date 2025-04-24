#include "BaseValidator.h"

class DefaultValidator : public BaseValidator<std::string>{
public:
	bool validate(std::string = ""){ return true;}
};