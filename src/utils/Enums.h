#include <Arduino.h>

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

enum CARD_TYPE {
    UNO = 14
};