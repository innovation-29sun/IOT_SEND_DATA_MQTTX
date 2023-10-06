#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char* ssid = "Jio_4G";
const char* password = "password";
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;
// lightsensor (LDR) is connected to GPIO 34 (Analog ADC1_CH6) 
const int LDRPin = 34;
int LDRValue = 0;
int Light_level = 0;
WiFiClient espClient;
PubSubClient client(espClient);

String deviceId = "1233-12as-ty12";

void setup_wifi() {
  delay(10);
  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("Connected to MQTT Broker");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Trying again in 5 seconds");
      delay(5000);
    }
  }
}

void send_data_to_mqtt() {
  StaticJsonDocument<200> doc;
  doc["deviceId"] = deviceId;
  JsonObject data = doc.createNestedObject("data");
  data["light_value_in_%"] = Light_level;  // Replace with actual sensor data
  data["humidity"] = random(40, 60);     // Replace with actual sensor data
  JsonArray tags = doc.createNestedArray("tags");
  tags.add("light_sensor");

  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer);
  String topic = "altrosyn/device/" + deviceId;

  client.publish(topic.c_str(), jsonBuffer);
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  LDRValue = analogRead(LDRPin);
  Light_level = map(LDRValue,0,3500,0,100);
  send_data_to_mqtt();
  delay(30000);  // Send data every 30 seconds
}
