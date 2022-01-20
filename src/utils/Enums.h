#include <Arduino.h>

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