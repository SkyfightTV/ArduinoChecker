#include "AChecker.h"

AChecker::AChecker(TYPE type, int pin, bool debug) {
    this->type = type;
    this->pin = pin;
    this->debug = debug;

    switch (this->type) {
        case DHT_11:
            if(debug)
                Serial.println("Check >> DHT_11");
            pinMode(pin, INPUT);
            this->dht = DHT(pin, DHT11);
            this->dht.begin();
            break;
        case DHT_12:
            if(debug)
                Serial.println("Check >> DHT_12");
            pinMode(pin, INPUT);
            this->dht = DHT(pin, DHT12);
            this->dht.begin();
            break;
        case DHT_21:
            if(debug)
                Serial.println("Check >> DHT_21");
            pinMode(pin, INPUT);
            this->dht = DHT(pin, DHT21);
            this->dht.begin();
            break;
        case DHT_22:
            if(debug)
                Serial.println("Check >> DHT_22");
            pinMode(pin, INPUT);
            this->dht = DHT(pin, DHT22);
            this->dht.begin();
            break;
        case AM_2301:
            if(debug)
                Serial.println("Check >> AM2301");
            pinMode(pin, INPUT);
            this->dht = DHT(pin, AM2301);
            this->dht.begin();
            break;
        default:
            break;
    }
}

Result AChecker::get() {
    switch (type) {
        case DHT_11:
        case DHT_12:
        case DHT_21:
        case DHT_22:
        case AM_2301:
            if(debug)
                Serial.println("Check >> DHT_11");
            return checkDHT(this->dht, this->pin, this->debug);
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
            return Result(TYPE_NULL, static_cast<const PIN_TYPE>(NULL), pin);
            break;
    }
}

DHT AChecker::getDHT() {
    return this->dht;
}

int AChecker::getPin() {
    return this->pin;
}

TYPE AChecker::getType() {
    return this->type;
}

bool AChecker::isDebug() {
    return this->debug;
}