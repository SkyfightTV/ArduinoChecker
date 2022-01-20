#include <malloc.h>
#include "Result.h"

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin)
{
    Result:Result(resultType, pinType, pin, malloc(sizeof(struct TAB)));
}

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, TAB *values)
{
    this->resultType = resultType;
    this->pinType = pinType;
    this->pin = pin;
    this->values = values;
}

RESULT_TYPE Result::getResultType()
{
    return this->resultType;
}

PIN_TYPE Result::getPinType()
{
    return this->pinType;
}

int Result::getPin() const
{
    return this->pin;
}

TAB* Result::getValues()
{
    return this->values;
}