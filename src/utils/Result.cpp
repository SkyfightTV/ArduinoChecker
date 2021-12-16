#include "Enums.h"

static int length(const double *s)
{
    int n;
    for (int i = 0; s[i] != '\0'; i++)
        n++;
    return n;
}

static void copy(double *from, double *to)
{
    int n = length(from);
    for (int i = 0; i < n; i++)
        to[i] = from[i];
}

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, int *values)
{
    this->resultType = resultType;
    this->pinType = pinType;
    this->pin = pin;
    copy(reinterpret_cast<double *>(values), this->values);
}

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, float *values)
{
    this->resultType = resultType;
    this->pinType = pinType;
    this->pin = pin;
    copy(reinterpret_cast<double *>(values), this->values);
}

Result::Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, double *values)
{
    this->resultType = resultType;
    this->pinType = pinType;
    this->pin = pin;
    copy(values, this->values);
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

double *Result::getValues()
{
    return this->values;
}