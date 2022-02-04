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
    SUCCESS = 1,
    FAILED = 0,
    PIN_NULL = 0,
    TYPE_NULL = 0
};