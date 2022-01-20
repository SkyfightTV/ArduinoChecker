#include "Result.h"

#define TAB(TYPE) struct {unsigned long int size; TYPE *data;}

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin)
{
    Result:Result(resultType, pinType, pin, new double[0]);
}

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, TAB(double) values)
{
    this->resultType = resultType;
    this->pinType = pinType;
    this->pin = pin;
    this->values = new double[values.size];

    for(unsigned i=0; i < values.size; i++)
        this->values[i] = values.data[i];
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

double* Result::getValues()
{
    return this->values;
}