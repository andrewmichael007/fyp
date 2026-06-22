#ifndef SOIL_MOISTURE_SENSOR_H
#define SOIL_MOISTURE_SENSOR_H

// creating a blueprint for soil moisture sensor basically what the soil moisture can do
class SoilMoistureSensor
{
public:
    bool begin();
    int readRaw();
    float readPercentage();

private:
    const int dryValue = 3500;
    const int wetValue = 1500;
};

#endif