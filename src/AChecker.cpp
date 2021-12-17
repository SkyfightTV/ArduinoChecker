#include "AChecker.h"

Result check(TYPE type, int pin, bool debug) {
    if(debug)
        Serial.println("Check >> Start");
    if (pin == -1) {
        if (debug)
            Serial.println("Check >> NULL PIN");
        float values[] = {};
        return Result(PIN_NULL, static_cast<const PIN_TYPE>(NULL), pin, values);
    }
    switch (type) {
        case DHT_11:
            if(debug)
                Serial.println("Check >> DHT_11");
            return checkDHT(11, pin, debug);
            break;
        case DHT_12:
            if(debug)
                Serial.println("Check >> DHT_12");
            return checkDHT(12, pin, debug);
            break;
        case DHT_21:
            if(debug)
                Serial.println("Check >> DHT_21");
            return checkDHT(21, pin, debug);
            break;
        case DHT_22:
            if(debug)
                Serial.println("Check >> DHT_22");
            return checkDHT(22, pin, debug);
            break;
        case AM_2301:
            if(debug)
                Serial.println("Check >> AM2301");
            return checkDHT(21, pin, debug);
            break;
        case PHOTORESISTOR:
            if(debug)
                Serial.println("Check >> Photo resistor");
            return checkPhotoresistor(pin, debug);
            break;
        case CTN:
            if(debug)
                Serial.println("Check >> CTN");
            return checkCTN(pin, debug);
            break;
        case RTC_CLOCK:
            if(debug)
                Serial.println("Check >> RTC_Clock");
            return checkRTC(debug);
            break;
        case POTENTIOMETER:
            if(debug)
                Serial.println("Check >> Potentiometer");
            return checkPotentiometer(pin, debug);
            break;
        case INFRARED_SENSOR:
            if(debug)
                Serial.println("Check >> infrared sensor");
            return checkInfraredSensor(pin, debug);
            break;
        default:
            if(debug)
                Serial.println("Check >> NULL");
            float values[] = {};
            return Result(TYPE_NULL, static_cast<const PIN_TYPE>(NULL), pin, values);
            break;
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
