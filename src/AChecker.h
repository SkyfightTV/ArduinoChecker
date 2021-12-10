#include "../lib/arduino/Arduino.h"
#include <iostream>

enum TYPE {
    DHT11,
    DHT12,
    DHT21,
    DHT22,
    AM2301,
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
    public:
        explicit Result(const RESULT_TYPE resultType, const PIN_TYPE pinType, const int pin, int *values) {
            this->resultType = resultType;
            this->pinType = pinType;
            this->pin = pin;
            std::copy(values, values + sizeof(values), this->values);
        }

        explicit Result(const RESULT_TYPE resultType, const PIN_TYPE pinType, const int pin, float *values) {
            this->resultType = resultType;
            this->pinType = pinType;
            this->pin = pin;
            std::copy(values, values + sizeof(values), this->values);
        }

        explicit Result(const RESULT_TYPE resultType, const PIN_TYPE pinType, const int pin, double *values) {
            this->resultType = resultType;
            this->pinType = pinType;
            this->pin = pin;
            std::copy(values, values + sizeof(values), this->values);
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

Result check(TYPE type, bool debug){
    check(type, -1, debug);
}

Result check(TYPE type){
    check(type, -1, true);
}

Result check(TYPE type, int pin) {
    check(type, pin, true);
}