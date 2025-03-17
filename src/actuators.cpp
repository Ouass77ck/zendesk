#include "actuators.h"
#include <Arduino.h>

#define RELAIS_PIN 5

void setupActuators() {
    pinMode(RELAIS_PIN, OUTPUT);
    digitalWrite(RELAIS_PIN, LOW);
}

void controlRelay(bool state) {
    digitalWrite(RELAIS_PIN, state ? HIGH : LOW);
}