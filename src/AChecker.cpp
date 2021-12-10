#include "AChecker.h"
#include <DHT.h>
#include <RTClib.h>

Result checkDHT(uint8_t name, int pin, bool debug);

Result checkPhotoresistor(int pin, bool debug);

Result checkCTN(int pin, bool debug);

Result checkRTC(bool debug);

Result checkPotentiometer(int pin, bool debug);

Result checkInfraredSensor(int pin, bool debug);

Result check(TYPE type, bool debug){
    check(type, -1, debug);
}

Result check(TYPE type){
    check(type, -1, true);
}

Result check(TYPE type, int pin) {
    check(type, pin, true);
}

Result check(TYPE type, int pin, bool debug) {
    float values[] = {};
    if (pin == 0)
        return Result(PIN_NULL, static_cast<const PIN_TYPE>(NULL), pin, values);
    switch (type) {
        case DHT_11:
            return checkDHT(*(uint8_t *) "DHT11", pin, debug);
        case DHT_12:
            return checkDHT(*(uint8_t *) "DHT12", pin, debug);
        case DHT_21:
            return checkDHT(*(uint8_t *) "DHT21", pin, debug);
        case DHT_22:
            return checkDHT(*(uint8_t *) "DHT22", pin, debug);
        case AM_2301:
            return checkDHT(*(uint8_t *) "AM2301", pin, debug);
        case PHOTORESISTOR:
            return checkPhotoresistor(pin, debug);
        case CTN:
            return checkCTN(pin, debug);
        case RTC_CLOCK:
            return checkRTC(debug);
        case POTENTIOMETER:
            return checkPotentiometer(pin, debug);
        case INFRARED_SENSOR:
            return checkInfraredSensor(pin, debug);
        default:
            return Result(TYPE_NULL, static_cast<const PIN_TYPE>(NULL), pin, values);
    }
}

Result checkDHT(uint8_t name, int pin, bool debug) {
    DHT dht(pin, name);
    dht.begin();
    float values[3] = {dht.readTemperature(), dht.readHumidity()};
    if (isnan(values[0]) || isnan(values[1]))
        return Result(FAILED, DIGITAL, pin, values);
    values[2] = dht.computeHeatIndex(values[0], values[1]);
    return Result(SUCCESS, DIGITAL, pin, values);
}

Result checkPhotoresistor(int pin, bool debug) {
    int value = analogRead(pin);
    int values[] = {value};
    return Result(values[0] == -999 ? FAILED : SUCCESS, ANALOG, pin, values);
}

Result checkCTN(int pin, bool debug) {
    int value = analogRead(pin);
    double values[] = {0.0};
    if (value == -999)
        return Result(FAILED, ANALOG, pin, values);
    double Ur = 5.0 * value / 1023;
    double result = (Ur - 1.19) / 52.8E-3;
    values[0] = result;
    return Result(SUCCESS, ANALOG, pin, values);
}

Result checkRTC(bool debug) {
    RTC_Millis rtc{};
    DateTime date = rtc.now();
    float values[] = {};
    unsigned long current = round(millis() / 1000);
    return Result(current != date.secondstime() ? FAILED : SUCCESS, RTC, -1, values);
}

Result checkPotentiometer(int pin, bool debug) {
    int value = analogRead(pin);
    int values[] = {value};
    return Result(values[0] == -999 ? FAILED : SUCCESS, ANALOG, pin, values);
}

Result checkInfraredSensor(int pin, bool debug) {
    int value = digitalRead(pin);
    int values[] = {value};
    return Result(value == 0 ? FAILED : SUCCESS, DIGITAL, pin, values);
}