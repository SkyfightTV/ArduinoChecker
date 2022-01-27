#include "utils/Checker.h"
#include <DHT.h>
#include <RTClib.h>

Result check(TYPE type, int pin, bool debug);

Result check(TYPE type, bool debug);

Result check(TYPE type);

Result check(TYPE type, int pin);

class AChecker {
private:
    TYPE type;
    int pin;
    bool debug;

    DHT dht = NULL;
public:
    AChecker(TYPE type, int pin, bool debug);

    Result get();

    TYPE getType();
    int getPin();
    bool isDebug();
    DHT getDHT();
};