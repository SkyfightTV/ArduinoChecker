#include "../lib/arduino/Arduino.h"
#include <algorithm>

enum TYPE {
    DHT_11
};

enum RESULT_TYPE {
    SUCCESS=HIGH,
    FAILED=LOW,
    PIN_NULL=LOW,
    TYPE_NULL=LOW,
    UNKNOWN=LOW
};

class Result {
    private:
        RESULT_TYPE type=UNKNOWN;
        int pin=0;
        int *values={};
    public:
        explicit Result(const RESULT_TYPE type, const int pin, int *values) {
            this->type=type;
            this->pin=pin;
            std::copy(values,values+sizeof(values),this->values);
        }

        RESULT_TYPE getType() const {
            return this->type;
        }

        int getPin() const {
            return this->pin;
        }

        int *getValues() const {
            return this->values;
        }
};

Result check(TYPE type, int pin, bool debug);
Result check(TYPE type, int pin) {
    check(type, pin, true);
}