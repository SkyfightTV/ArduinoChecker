#include <cstring>
#include "Result.h"

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin)
{
    Result(resultType, pinType, pin, new double[0]);
}

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, double* values)
{
    this->resultType = resultType;
    this->pinType = pinType;
    this->pin = pin;
    this->values = new double[sizeof values];
    memcpy(this->values, values, sizeof values);
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

double* Result::getValues()
{
    return this->values
}