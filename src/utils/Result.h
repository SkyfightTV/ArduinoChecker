#include "Enums.h"

class Result {
private:
    RESULT_TYPE resultType = static_cast<RESULT_TYPE>(NULL);
    PIN_TYPE pinType = static_cast<PIN_TYPE>(NULL);
    int pin = 0;
    double *values = {};

    static void copy(double *from, double *to) {
        int n = length(from);
        for (int i = 0; i < n; i++)
            to[i] = from[i];
    }

    static int length(const double* s)
    {
        int n;
        for (int i = 0; s[i] != '\0'; i++)
            n++;
        return n;
    }
public:
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, int *values) {
        this->resultType = resultType;
        this->pinType = pinType;
        this->pin = pin;
        copy(reinterpret_cast<double *>(values), this->values);
    }

    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, float *values) {
        this->resultType = resultType;
        this->pinType = pinType;
        this->pin = pin;
        copy(reinterpret_cast<double *>(values), this->values);
    }

    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, double *values) {
        this->resultType = resultType;
        this->pinType = pinType;
        this->pin = pin;
        copy(values, this->values);
    }

    RESULT_TYPE getResultType() const {
        return this->resultType;
    }

    PIN_TYPE getPinType() const {
        return this->pinType;
    }

    int getPin() const {
        return this->pin;
    }

    double *getValues() const {
        return this->values;
    }
};