#include <Arduino.h>
//Biblioteca
#include <ESP8266WiFiMesh.h>

//Constantes - Conexão Wifi
const char* ssid = "fog";
const char* password = "projetofog";
WiFiClient espClient;


//Função de Conexão do ESP com a Wifi
void start_wifi() {
  delay(3000);
  Serial.println("\nTentativa conexão do ESP com a rede WIFI...");
  Serial.println("\nssid\t=>\t"+String(ssid));
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED) {
    Serial.println("\nAguardar enquanto o ESP tenta conectar com o SSID\t=>\t"+String(ssid));
    delay(3000);
    }
    Serial.println("\nDispositivo conectado!");
    Serial.print("Endereço IPv4 => ");Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  start_wifi();
}

void loop() {
  // put your main code here, to run repeatedly:

}