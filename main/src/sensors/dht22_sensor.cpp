#include "dht22_sensor.h"
#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

static DHT dht(DHT_PIN, DHT_TYPE);

bool DHT22Sensor::begin()
{
    dht.begin();
    return true;
}

float DHT22Sensor::readTemperature()
{
    return dht.readTemperature();
}

float DHT22Sensor::readHumidity()
{
    return dht.readHumidity();
}
