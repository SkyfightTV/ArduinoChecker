#include "AChecker.h"
#include "../lib/dht11/dht11.h"

Result checkDHT11(int pin, bool debug);

Result checkPhotoresistor(int pin, bool debug);

Result check(TYPE type, int pin, bool debug) {
    if (pin == 0)
        return Result(PIN_NULL, static_cast<const PIN_TYPE>(NULL), pin, {});
    switch (type) {
        case DHT_11:
            return checkDHT11(pin, debug);
        case PHOTORESISTOR:
            return checkPhotoresistor(pin, debug);
        default:
            return Result(TYPE_NULL, static_cast<const PIN_TYPE>(NULL), pin, {});
    }
}

Result checkDHT11(int pin, bool debug) {
    dht11 dht{};
    dht.read(pin);
    int values[] = {dht.temperature, dht.humidity};
    if (values[0] == -999 || values[1] == -999)
        return Result(FAILED, DIGITAL, pin, values);
    return Result(SUCCESS, DIGITAL, pin, values);
}

Result checkPhotoresistor(int pin, bool debug) {
    int value = analogRead(pin);
    int values[] = {value};
    if (values[0] == -999)
        return Result(FAILED, ANALOG, pin, values);
    return Result(SUCCESS, ANALOG, pin, values);
}