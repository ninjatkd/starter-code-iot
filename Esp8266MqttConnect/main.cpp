#include <Arduino.h>
//Biblioteca
#include <ESP8266WiFiMesh.h>
#include <PubSubClient.h>

//Constantes - Conexão Wifi
const char* ssid = "fog2";
const char* password = "projetofog";
WiFiClient espClient;

//Constantes - Conexão MQTT Broker "Mosquitto"
const char* mqttServer = "10.0.2.1";
const int mqttPort = 1883;
const char* mqttUser = "admin";
const char* mqttPassword = "admin";
PubSubClient client(espClient);


//Função de Conexão e Reconexão do ESP com a Wifi.
void start_wifi() {
  delay(3000);
  Serial.println("Conexão do ESP8266 com a rede WIFI"+String(ssid));
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED) {
    Serial.println("\nTentativa de conexão com o SSID\t=>\t"+String(ssid));
    delay(3000);
    }
    Serial.println("\nDispositivo conectado na rede Wifi.");
    Serial.print("Endereço IPv4 => ");Serial.println(WiFi.localIP());
}

//Função de Conexão e Reconexão do ESP com o Brocker
void ConnectMqttBroker() {
  delay(3000);
  Serial.println("\nTentativa conexão do ESP com o Broker MQTT...");
  Serial.println("\nIP e Porta do MQTT Server\t=>\t"+String(mqttServer)+":"+String(mqttPort));
  client.setServer(mqttServer,mqttPort);
  
  while (!client.connected()) {
    Serial.println("Tentativa de conexão com o broker MQTT...");
    
    if (client.connect("ESP8266Client",mqttUser,mqttPassword)){
      Serial.println("Conectado ao Broker Mqtt!");
      } else {
      Serial.print("Falha na conexão com o broker - Estado:")+String(client.state());
      delay(2000);
      }
   }
}


void setup() {
  Serial.begin(9600);
  start_wifi();
  
}

void loop() {
  if(!client.connected()) {
    ConnectMqttBroker();
  }
  client.loop();
}
