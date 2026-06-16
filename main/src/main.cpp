// the main.cpp is the PlatformIO template. It contains the the system architecture.

// this is the test code for humidity and temperature sensor

//header files
#include <Arduino.h>
#include <DHT.h>

//define pin and dht type
#define DHT_PIN 4
#define DHT_TYPE DHT22

//call the dht function
DHT dht(DHT_PIN, DHT_TYPE);


void setup()
{
    Serial.begin(115200);
    dht.begin();

    Serial.println("DHT22 Test Starting...");
}

void loop()
{
    // defining temperature and humidity as float 
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // we first check if temperature and humidity readings is not a number
    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println("ERROR: failed to read from DHT22");
        return;
    }   
    // if they are numbers, do this...
    else
    {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C    ");

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    }

    //DHT22 reads data every 2 seconds
    delay(2000);
}

