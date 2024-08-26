#include <Arduino.h>
#include <U8g2lib.h>
#include "saidas.h"
#include "iot.h"

//Definição dos pinos dos leds
#define LedBuiltInPin 26
#define SecondLedBuiltInPin 2

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

//Variaveis de controle dos leds
bool LedBuiltInState = LOW;
bool SecondLedBuiltInState = LOW;


// Inicializa as saidas digitais
void inicializa_saidas()
{
    u8g2.begin();
    pinMode(LedBuiltInPin, OUTPUT);
    pinMode(SecondLedBuiltInPin, OUTPUT);
}

// Atualiza as saidas digitais
void atualiza_saidas()
{
    digitalWrite(LedBuiltInPin, LedBuiltInState);   
    digitalWrite(SecondLedBuiltInPin, SecondLedBuiltInState);

}

void display()
{
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_profont11_tf);
  u8g2.setCursor(0, 10);
  u8g2.print("Senha: ");
  u8g2.setCursor(50, 10);
  u8g2.print(aleatorio);
  u8g2.sendBuffer();
}