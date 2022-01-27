#include "Enums.h"

class TAB {
public:
    TAB();

    unsigned long int size;
    double *data;
};

class Result{
private:
    RESULT_TYPE resultType;
    PIN_TYPE pinType;
    int pin{};
    TAB* values{};
public:
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin);
    Result(RESULT_TYPE resultType, PIN_TYPE pinType, int pin, TAB *values);

    RESULT_TYPE getResultType();
    PIN_TYPE getPinType();
    int getPin() const;
    TAB* getValues();

};