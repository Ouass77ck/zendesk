#include <Arduino.h>
#include "wifi_mqtt.h"
#include "sensors.h"
#include "actuators.h"

void setup() {
    Serial.begin(115200);
    setupWiFiMQTT();
    setupSensors();
    setupActuators();
}

void loop() {
    handleMQTT();
    readSensors();
    delay(2000);
}