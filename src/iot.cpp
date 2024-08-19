#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h> // Baixar a biblioteca PubSubClient
#include <TimeLib.h>
#include "iot.h"
#include "senhas.h"
#include "saidas.h"
#include "Atuadores.h"
#include <U8g2lib.h>
#include <ArduinoJson.h>

float var_temperatura;
float var_pressao;
float var_altitude;
int var_umidade;
float var_co2;
unsigned long var_timestamp;



// Definição dos tópicos de inscrição
#define mqtt_topic1 "projeto/fidelis"
#define mqtt_topic2 "projeto/fidelisTeste2"
#define mqtt_topic3 "projetoFidelis/servo"
#define mqtt_topic4 "projetoFidelis/DHT22"
#define mqtt_topicSenai "projeto_integrado/SENAI134/Cienciadedados/GrupoX"

// Definição do ID do cliente MQTT randomico
const String cliente_id = "ESP32Client" + String(random(0xffff), HEX);

// Definição dos dados de conexão
WiFiClient espClient;
PubSubClient client(espClient);

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// Protótipos das funções
void tratar_msg(char *topic, String msg);
void callback(char *topic, byte *payload, unsigned int length);
void reconecta_mqtt();
void inscricao_topicos();

// Inicia a conexão WiFi
void setup_wifi()
{
  u8g2.begin();
  Serial.println();
  Serial.print("Conectando-se a Rede WiFi ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Conectado ao WiFi com sucesso com IP: ");
  Serial.println(WiFi.localIP());
}

// Inicia a conexão MQTT
void inicializa_mqtt()
{
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

// Atualiza a conexão MQTT
void atualiza_mqtt()
{

  client.loop();
  if (!client.connected())
  {
    reconecta_mqtt();
  }
}

// Função de callback chamada quando uma mensagem é recebida
void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.printf("Mensagem recebida [ %s ] \n\r", topic);
  String msg = "";
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
    msg += (char)payload[i];
  }
  Serial.println();
  tratar_msg(topic, msg);
  
}

// Função de reconexão ao Broker MQTT
void reconecta_mqtt()
{
  while (!client.connected())
  {
    Serial.print("Tentando se conectar ao Broker MQTT: ");
    Serial.println(mqtt_server);
    if (client.connect(cliente_id.c_str()))
    {
      Serial.println("Conectado ao Broker MQTT");
      inscricao_topicos();
    }
    else
    {
      Serial.println("Falha ao conectar ao Broker.");
      Serial.println("Havera nova tentativa de conexao em 2 segundos");
      delay(2000);
    }
  }
}

// Publica uma mensagem no tópico MQTT
void publica_mqtt(String topico, String msg)
{
  client.publish(topico.c_str(), msg.c_str());
}

//!----------------------------------------
// TODO Alterar a programação apartir daqui
//!----------------------------------------

// Inscreve nos tópicos MQTT
void inscricao_topicos()
{
  // client.subscribe(mqtt_topic1); // led 1
  client.subscribe(mqtt_topic2); // led 2
  // client.subscribe(mqtt_topic3); // Servo
  // client.subscribe(mqtt_topic4); // DHT
  // client.subscribe(mqtt_topicSenai);
}

// Trata as mensagens recebidas
void tratar_msg(char *topic, String msg)
{
  // JsonDocument doc;
  // deserializeJson(doc, msg); // Deserialization
  // if (doc.containsKey("temperature")) // Validacao de dadossss
  // var_temperatura = doc["temperature"]; 

  // if (doc.containsKey("pressure"))
  // var_pressao = doc["pressure"];

  // if (doc.containsKey("altitude"))
  // var_altitude = doc["altitude"];

  // if (doc.containsKey("humidity"))
  // var_umidade = doc["humidity"];

  // if (doc.containsKey("CO2"))
  // var_co2 = doc["CO2"];

  // if (doc.containsKey("timestamp"))
  // var_timestamp = doc["timestamp"];

  // u8g2.clearBuffer();
  // u8g2.setFont(u8g2_font_profont11_tf);
  // u8g2.setCursor(0, 10); 
  // u8g2.print("Temperatura: ");
  // u8g2.setCursor(80, 10);
  // u8g2.print(var_temperatura);
  // u8g2.setCursor(0, 20);
  // u8g2.print("Pressao: ");
  // u8g2.setCursor(60,20);
  // u8g2.print(var_pressao);
  // u8g2.setCursor(0, 30);
  // u8g2.print("Altitude: ");
  // u8g2.setCursor(60, 30);
  // u8g2.print(var_altitude);
  // u8g2.setCursor(0, 40);
  // u8g2.print("Umidade: ");
  // u8g2.setCursor(50, 40);
  // u8g2.print(var_umidade);
  // u8g2.setCursor(0, 50);
  // u8g2.print("CO2: ");
  // u8g2.setCursor(30, 50);
  // u8g2.print(var_co2);
  // u8g2.setCursor(0, 60);
  // u8g2.print("Timestamp: ");
  // u8g2.setCursor(70, 60);
  // u8g2.print(var_timestamp);
  // u8g2.sendBuffer(); 

  // setTime(var_timestamp);
  // Serial.printf("%02d/%02d/%04d %02d:%02d:%02d \n", day(), month(), year());
  // Serial.printf(" %02d:%02d:%02d \n", hour(), minute(), second());
  // if (strcmp(topic, mqtt_topic1) == 0)
  // {
  //   if (msg == "liga")
  //   {
  //     LedBuiltInState = true;
  //   }
  //   else if (msg == "desliga")
  //   {
  //     LedBuiltInState = false;
  //   }
  //   else if (msg == "alterna")
  //   {
  //     LedBuiltInState = !LedBuiltInState;
  //   }
  //   else
  //   {
  //     Serial.println("Comando desconhecido");
  //   }
  // }

  // else if (strcmp(topic, mqtt_topic2) == 0)
  // {
  //   if (msg == "liga")
  //   {
  //     SecondLedBuiltInState = true;
  //   }
  //   else if (msg == "desliga")
  //   {
  //     SecondLedBuiltInState = false;
  //   }
  //   else if (msg == "alterna")
  //   {
  //     SecondLedBuiltInState = !SecondLedBuiltInState;
  //   }
  //   else
  //   {
  //     Serial.println("Comando desconhecido");
  //   }
  // }

  // else if (strcmp(topic, mqtt_topic3) == 0)
  // {
  //   posiciona_servo(msg.toInt());
  // }
  // else if (strcmp(topic, mqtt_topic4) == 0)
  // {
  //   deserializeJson(doc, msg);
  //   float umidade = doc["umidade"];
  //   float temperatura = doc["temperatura"];

  //   Serial.print("Umidade: ");
  //   Serial.print(umidade);
  //   Serial.print(" %\t");
  //   Serial.print("Temperatura: ");
  //   Serial.println(temperatura);
  //   Serial.println(" *C ");
  // }
 
}

