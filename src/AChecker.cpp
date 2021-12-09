#include "AChecker.h"
#include "../lib/dht11/dht11.h"

Result check_DHT_11(int pin, bool debug);

Result check(TYPE type, int pin, bool debug) {
    if (pin==0)
        return Result(PIN_NULL, pin, {});
    switch (type) {
        case DHT_11:
            return check_DHT_11(pin,debug);
        default:
            return Result(TYPE_NULL,pin,{});
    }
}

Result check_DHT_11(int pin, bool debug) {
    dht11 dht{};
    dht.read(pin);
    int values[]={dht.temperature,dht.humidity};
    if(dht.temperature==-999||dht.humidity==-999)
        return Result(FAILED,pin,values);
    return Result(SUCCESS,pin,values);
}