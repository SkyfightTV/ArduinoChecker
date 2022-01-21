#include "Result.h"
#include <DHT.h>
#include <RTClib.h>

Result checkDHT(DHT dht, int pin, bool debug);

Result checkPhotoresistor(int pin, bool debug);

Result checkCTN(int pin, bool debug);

Result checkRTC(bool debug);

Result checkPotentiometer(int pin, bool debug);

Result checkInfraredSensor(int pin, bool debug);