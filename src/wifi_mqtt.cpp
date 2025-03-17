#include "wifi_mqtt.h"
#include "actuators.h"

const char* ssid = "ssid";
const char* password = "password";
const char* mqttServer = "192.168.1.100";
const int mqttPort = 1883;
WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
    String message;
    for (int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
    if (String(topic) == "bureau/relais") {
        controlRelay(message == "ON");
    }
}

void setupWiFiMQTT() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connexion WiFi...");
    }
    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);
    while (!client.connected()) {
        client.connect("ESP32Client");
    }
    client.subscribe("bureau/relais");
}

void handleMQTT() {
    client.loop();
}
