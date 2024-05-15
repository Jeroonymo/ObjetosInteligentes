#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "NOME_DO_WIFI";
const char* password = "SENHA_DO_WIFI";
const char* mqtt_server = "IP_DO_MQTT_SERVER";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP8266Client")) {
      // Connected to MQTT broker
    } else {
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');

    if (line.length() > 0) { 
      int dB = line.toInt();

      String payload = String(dB);
      client.publish("decibelimeter/reading", (char*) payload.c_str());
    }
  }
}