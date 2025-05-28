#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883; 
const char* mqttTopicDevice = "wokwi/jkan/test-0/device"; 
const char* mqttTopicWeb = "wokwi/jkan/test-0/web";

char* clientId = "clientId-jk635-0";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  
    // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");

 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnectMQTTClient();
  client.loop();
  delay(10); 
}

void reconnectMQTTClient() {
  Serial.println("Connecting to MQTT cluster"); 
  while (!client.connected()) {
    if (client.connect(clientId)) {
      Serial.print(clientId);
      Serial.println(" connected");
      client.subscribe(mqttTopicDevice);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
  }
  Serial.println();
  Serial.print("Publishing on topic: ");
  Serial.print(topic);
  const char* reply  = "Message received";
  client.publish(mqttTopicWeb, reply);

}
