#include "utils/Result.h"
#include "utils/Checker.h"
#include <DHT.h>
#include <RTClib.h>

Result check(TYPE type, int pin, bool debug);

Result check(TYPE type, bool debug);

Result check(TYPE type);

Result check(TYPE type, int pin);