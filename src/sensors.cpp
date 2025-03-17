#include "sensors.h"
#include <Wire.h>
#include <BH1750.h>
#include "wifi_mqtt.h"
#define PIR_PIN 14
#define CURRENT_SENSOR_PIN 34

BH1750 lightMeter;

void setupSensors() {
    pinMode(PIR_PIN, INPUT);
    Wire.begin();
    lightMeter.begin();
}

void readSensors() {
    bool presence = digitalRead(PIR_PIN);
    float lux = lightMeter.readLightLevel();
    int sensorValue = analogRead(CURRENT_SENSOR_PIN);
    float voltage = sensorValue * (3.3 / 4096.0);
    
    char luxString[8], powerString[8];
    dtostrf(lux, 6, 2, luxString);
    dtostrf(voltage, 6, 2, powerString);
    
    client.publish("bureau/presence", presence ? "1" : "0");
    client.publish("bureau/luminosite", luxString);
    client.publish("bureau/consommation", powerString);
}