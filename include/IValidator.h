#ifndef IVALIDATOR_H
#define IVALIDATOR_H

class IValidator {
public:
    virtual ~IValidator() = default;
    virtual bool validate(double amount) = 0;
};

#endif
