#include <Arduino.h>
#include "../lib/arduino/Arduino.h"

enum TYPE {
    DHT_11,
    DHT_12,
    DHT_21,
    DHT_22,
    AM_2301,
    PHOTORESISTOR,
    CTN,
    RTC_CLOCK,
    POTENTIOMETER,
    SLIDE_SWITCH,
    INFRARED_SENSOR
};

enum PIN_TYPE {
    ANALOG,
    DIGITAL,
    RTC
};

enum RESULT_TYPE {
    SUCCESS = HIGH,
    FAILED = LOW,
    PIN_NULL = LOW,
    TYPE_NULL = LOW
};

class Result {
private:
    RESULT_TYPE resultType = static_cast<RESULT_TYPE>(NULL);
    PIN_TYPE pinType = static_cast<PIN_TYPE>(NULL);
    int pin = 0;
    double *values = {};

    static void *copy(double *from, double *to) {
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
    explicit Result(const RESULT_TYPE resultType, const PIN_TYPE pinType, const int pin, int *values) {
        this->resultType = resultType;
        this->pinType = pinType;
        this->pin = pin;
        copy(reinterpret_cast<double *>(values), this->values);
    }

    explicit Result(const RESULT_TYPE resultType, const PIN_TYPE pinType, const int pin, float *values) {
        this->resultType = resultType;
        this->pinType = pinType;
        this->pin = pin;
        copy(reinterpret_cast<double *>(values), this->values);
    }

    explicit Result(const RESULT_TYPE resultType, const PIN_TYPE pinType, const int pin, double *values) {
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

Result check(TYPE type, int pin, bool debug);

Result check(TYPE type, bool debug);

Result check(TYPE type);

Result check(TYPE type, int pin);