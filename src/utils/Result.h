#include "Enums.h"

static int length(const double *s);
static void copy(double *from, double *to);

class Result{
private:
    RESULT_TYPE resultType = static_cast<RESULT_TYPE>(NULL);
    PIN_TYPE pinType = static_cast<PIN_TYPE>(NULL);
    int pin = 0;
    double *values = {};
public:
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, int *values);
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, float *values);
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, double *values);

    RESULT_TYPE getResultType();
    PIN_TYPE getPinType();
    int getPin();
    double *getValues();
};