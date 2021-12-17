#include "AChecker.h"
#include <DHT.h>
#include <RTClib.h>

Result checkDHT(uint8_t name, int pin, bool debug) {
    if(debug)
        Serial.println("DHT >> Start checking");
    DHT dht(pin, name);
    dht.begin(true);
    float values[3] = {dht.readTemperature(), dht.readHumidity()};
    if (isnan(values[0]) || isnan(values[1])) {
        if (debug)
            Serial.println("DHT >> Failed Result");
        return Result(FAILED, DIGITAL, pin, values);
    }
    values[2] = dht.computeHeatIndex(values[0], values[1]);
    if (debug) {
        Serial.println("DHT >> Success Result | Values : ");
        for (int i = 0; i <3;i++) {
            Serial.print("Valeur n°");
            Serial.print(i);
            Serial.print(" : ");
            Serial.println(values[i]);
        }
    }
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
            //return checkDHT(11, pin, debug);
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
