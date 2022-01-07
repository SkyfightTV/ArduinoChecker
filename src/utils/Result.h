#include "Enums.h"

class Result{
private:
    RESULT_TYPE resultType;
    PIN_TYPE pinType;
    int pin;
    double* values;
public:
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin);
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, double* values);

    RESULT_TYPE getResultType();
    PIN_TYPE getPinType();
    int getPin();
    double* getValues();

};