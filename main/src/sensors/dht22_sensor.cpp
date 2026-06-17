#include "dht22_sensor.h"
#include <Arduino.h>
#include <DHT.h>


#define DHT_PIN 4
#define DHT_TYPE DHT22

static DHT dht(DHT_PIN, DHT_TYPE);

bool DHTSensor::begin()
{
    dht.begin();
    return true;
}

float DHTSensor::readTemperature()
{
    return dht.readTemperature();
}

float DHTSensor::readHumidity()
{
    return dht.readHumidity();
}
