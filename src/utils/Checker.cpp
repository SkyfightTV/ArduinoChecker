#include "Checker.h"

Result checkDHT(DHT dht, int pin, bool debug)
{
    if(debug)
        Serial.println("DHT >> Start checking");
    dht.begin();
    struct TAB *values = malloc(sizeof(struct TAB));
    values->size = 3;
    values->data[0] = dht.readTemperature();
    values->data[1] = dht.readHumidity();
    if (isnan(values->data[0]) || isnan(values->data[1])) {
        if (debug)
            Serial.println("DHT >> Failed Result");
        return Result(FAILED, DIGITAL, pin);
    }
    values->data[2] = dht.computeHeatIndex(values[0], values[1]);
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

Result checkPhotoresistor(int pin, bool debug)
{
    int value = analogRead(pin);
    struct TAB *values = malloc(sizeof(struct TAB));
    values->size = 1;
    values->data[0] = value;
    return Result(values->data[0] == -999 ? FAILED : SUCCESS, ANALOG, pin, values);
}

Result checkCTN(int pin, bool debug)
{
    int value = analogRead(pin);
    if (value == -999)
        return Result(FAILED, ANALOG, pin);
    double Ur = 5.0 * value / 1023;
    double result = (Ur - 1.19) / 52.8E-3;
    struct TAB *values = malloc(sizeof(struct TAB));
    values->size = 1;
    values->data[0] = result;
    return Result(SUCCESS, ANALOG, pin, values);
}

Result checkRTC(bool debug)
{
    RTC_Millis rtc{};
    DateTime date = rtc.now();
    struct TAB *values = malloc(sizeof(struct TAB));
    values->size = 1;
    unsigned long current = round(millis() / 1000);
    values->data[0] = date.secondstime();
    return Result(current != date.secondstime() ? FAILED : SUCCESS, RTC, -1, values);
}

Result checkPotentiometer(int pin, bool debug)
{
    struct TAB *values = malloc(sizeof(struct TAB));
    values->size = 1;
    values->data[0] = analogRead(pin);
    return Result(values->data[0] == -999 ? FAILED : SUCCESS, ANALOG, pin, values);
}

Result checkInfraredSensor(int pin, bool debug)
{
    struct TAB *values = malloc(sizeof(struct TAB));
    values->size = 1;
    values->data[0] = digitalRead(pin);
    return Result(values->data[0] == 0 ? FAILED : SUCCESS, DIGITAL, pin, values);
}
