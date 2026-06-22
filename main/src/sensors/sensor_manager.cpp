//main implementation of sensor manager
#include "sensor_manager.h"
#include <Arduino.h>

bool SensorManager::begin()
{
    dht22Sensor.begin();
    SoilMoistureSensor.begin();
    bh1750Sensor.begin();

    return true;
}

//implemenation of getSensorData function
SensorData SensorManager::getSensorData()
{
    //creating a data object 
    SensorData data;

    data.valid = true;

    data.status = SensorStatus::OK;

    data.temperature = dht22Sensor.readTemperature();

    data.humidity = dht22Sensor.readHumidity();

    data.soilMoisture = SoilMoistureSensor.readPercentage();

    data.lightIntensity = bh1750Sensor.readLux();

    data.timestamp = millis();

    //validating the data
    if (isnan(data.temperature))
    {
        data.valid = false;
        data.status = SensorStatus::DHT_TEMPERATURE_ERROR;
        return data;
    }

    if (isnan(data.humidity))
    {
        data.valid = false;
        data.status = SensorStatus::DHT_HUMIDITY_ERROR;
        return data;
    }

    if (isnan(data.lightIntensity))
    {
        data.valid = false;
        data.status = SensorStatus::LIGHT_SENSOR_ERROR;
        return data;
    }

    return data;
}