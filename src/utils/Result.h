#include "Enums.h"

static int length(const double *s);
static void copy(double *from, double *to);

class Result{
private:
    RESULT_TYPE resultType;
    PIN_TYPE pinType;
    int pin;
public:
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin);
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin);
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin);

    RESULT_TYPE getResultType();
    PIN_TYPE getPinType();
    int getPin();
};