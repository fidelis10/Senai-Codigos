/*************************
 * Projeto IOT com ESP32
 * Escola SENAI de Informática
 * Curso de Apredizagem industrial
 * Integrador de soluções em nuvem
 * Data: 07/08/2024
 *
 * Autor: Lucas Fidelis de Lima
 *
 * Descrição: Projeto de automação utilizando ESP32
 * com conexão WiFi e MQTT.
 *
 * versão: 0.9
 */

#include <Arduino.h>
#include "iot.h"
#include "saidas.h"
#include "entradas.h"
#include "tempo.h"
#include <DHTesp.h>
#include "Atuadores.h"
#include <ArduinoJson.h>
#include <U8g2lib.h>

unsigned long tempo_anterior = 0;
const unsigned long intervalo = 1000;

#define BOTAO_BOOT_PIN 12
#define SECOND_BOTAO_BOOT_PIN 0

// Criacao de objetos
DHTesp dht;

#define DHTPIN 32

/******Objetos*******/

// Definicao dos topicos de publicacao
#define mqtt_pub_topic1 "projeto/fidelis"
#define mqtt_pub_topic2 "projeto/fidelisTeste2"
#define mqtt_pub_topic3 "projetoFidelis/DHT22"

// Protótipos das funções do main.cpp
void acao_botao_boot_pressionado();

void setup()
{

  dht.setup(DHTPIN, DHTesp::DHT22);
  Serial.begin(115200);
  setup_wifi();
  setup_time();
  inicializa_entradas();
  inicializa_saidas();
  inicializa_mqtt();
  inicializa_servo();
}

void loop()
{

  atualiza_time();
  atualiza_saidas();
  atualiza_botoes();
  atualiza_mqtt();

  // if (millis() - tempo_anterior >= intervalo)
  // {
  //   tempo_anterior = millis();
  // float umidade = dht.getHumidity();
  // float temperatura = dht.getTemperature();

  // doc["umidade"] = umidade;
  // doc["temperatura"] = temperatura;
  // doc["angulo"] = angulo;
  // doc["EstadoLed"] = LedBuiltInState;
  // doc["EstadoLed2"] = SecondLedBuiltInState;
  // doc["botao"] = !estado_botaointerno();
  // doc["botao2"] = !estado_botaoexterno();

  // serializeJson(doc, json);

  // publica_mqtt(mqtt_pub_topic3, json);

  // }

  // acao_botao_boot_pressionado();
  if (millis() - tempo_anterior >= intervalo)
  {
    tempo_anterior = millis();
    String json;
    JsonDocument doc;
    doc["TimeStamp"] = timeStamp();
    serializeJson(doc, json);
    publica_mqtt(mqtt_pub_topic2, json);
  }
  if (second_botao_boot_pressionado())
  {
    SecondLedBuiltInState = !SecondLedBuiltInState;
    String json_01;
    JsonDocument doc_01;
    doc_01["TimeStamp"] = timeStamp();
    doc_01["botao"] = !estado_botaointerno();
    doc_01["EstadoLed2"] = SecondLedBuiltInState;
    serializeJson(doc_01, json_01);
    publica_mqtt(mqtt_pub_topic2, json_01);
  }
}

// Função que verifica se o botão foi pressionado e sua ação
// void acao_botao_boot_pressionado()
// {
//   if (botao_boot_pressionado())
//   {
//     LedBuiltInState = !LedBuiltInState;
//     if (LedBuiltInState)
//       publica_mqtt(mqtt_pub_topic1, "Ligado");
//     else
//       publica_mqtt(mqtt_pub_topic1, "Desligado");
//   }
//   else if (second_botao_boot_pressionado())
//   {
//     SecondLedBuiltInState = !SecondLedBuiltInState;
//     if (SecondLedBuiltInState)
//       publica_mqtt(mqtt_pub_topic2, "Ligado");
//     else
//       publica_mqtt(mqtt_pub_topic2, "Desligado");
//   }
// }
