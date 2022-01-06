#include "Result.h"

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin)
{
    this->resultType = resultType;
    this->pinType = pinType;
    this->pin = pin;
}

RESULT_TYPE Result::getResultType()
{
    return this->resultType;
}

PIN_TYPE Result::getPinType()
{
    return this->pinType;
}

int Result::getPin()
{
    return this->pin;
}