#include "AChecker.h"

Result check(TYPE type, int pin, bool debug) {
    float values[] = {};
    if (pin == -1) {
        if (debug)
            Serial.println("Check >> NULL PIN");
        return Result(PIN_NULL, static_cast<const PIN_TYPE>(NULL), pin, values);
    }
    switch (type) {
        case DHT_11:
            if(debug)
                Serial.println("Check >> DHT_11");
            return checkDHT(*(uint8_t *) "DHT11", pin, debug);
        case DHT_12:
            if(debug)
                Serial.println("Check >> DHT_12");
            return checkDHT(*(uint8_t *) "DHT12", pin, debug);
        case DHT_21:
            if(debug)
                Serial.println("Check >> DHT_21");
            return checkDHT(*(uint8_t *) "DHT21", pin, debug);
        case DHT_22:
            if(debug)
                Serial.println("Check >> DHT_22");
            return checkDHT(*(uint8_t *) "DHT22", pin, debug);
        case AM_2301:
            if(debug)
                Serial.println("Check >> AM2301");
            return checkDHT(*(uint8_t *) "AM2301", pin, debug);
        case PHOTORESISTOR:
            if(debug)
                Serial.println("Check >> Photo resistor");
            return checkPhotoresistor(pin, debug);
        case CTN:
            if(debug)
                Serial.println("Check >> CTN");
            return checkCTN(pin, debug);
        case RTC_CLOCK:
            if(debug)
                Serial.println("Check >> RTC_Clock");
            return checkRTC(debug);
        case POTENTIOMETER:
            if(debug)
                Serial.println("Check >> Potentiometer");
            return checkPotentiometer(pin, debug);
        case INFRARED_SENSOR:
            if(debug)
                Serial.println("Check >> infrared sensor");
            return checkInfraredSensor(pin, debug);
        default:
            if(debug)
                Serial.println("Check >> NULL");
            return Result(TYPE_NULL, static_cast<const PIN_TYPE>(NULL), pin, values);
    }
}

Result check(TYPE type, bool debug){
    check(type, -1, debug);
}

Result check(TYPE type){
    check(type, -1, true);
}

Result check(TYPE type, int pin) {
    check(type, pin, true);
}
