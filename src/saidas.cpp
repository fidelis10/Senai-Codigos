#include <Arduino.h>
#include "saidas.h"

//Definição dos pinos dos leds
#define LedBuiltInPin 25
#define SecondLedBuiltInPin 2

//Variaveis de controle dos leds
bool LedBuiltInState = LOW;
bool SecondLedBuiltInState = LOW;


// Inicializa as saidas digitais
void inicializa_saidas()
{
    pinMode(LedBuiltInPin, OUTPUT);
    pinMode(SecondLedBuiltInPin, OUTPUT);
}

// Atualiza as saidas digitais
void atualiza_saidas()
{
    digitalWrite(LedBuiltInPin, LedBuiltInState);   
    digitalWrite(SecondLedBuiltInPin, SecondLedBuiltInState);

}
