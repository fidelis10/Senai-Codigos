#include <Arduino.h>
#include <Bounce2.h>
#include "entradas.h"
#include "saidas.h"

//Definição dos pinos dos botões




#define BOTAO 12
#define SECOND_BOTAO_BOOT_PIN 0

//Criação dos objetos para debouncing
Bounce botao_boot = Bounce();
Bounce second_botao_boot = Bounce();

// Inicializa as entradas
void inicializa_entradas()
{
    botao_boot.attach(BOTAO, INPUT_PULLUP);
    second_botao_boot.attach(SECOND_BOTAO_BOOT_PIN, INPUT_PULLUP);
}

// Atualiza o estado dos botoes
void atualiza_botoes()
{
    // Atualiza o estado do botao
    botao_boot.update(); 
    second_botao_boot.update(); 
    
}
//Retorna se o botão boot foi pressionado
bool botao_boot_pressionado() 
{
    return botao_boot.fell();
}
//Retorna se o botão boot foi pressionado
bool second_botao_boot_pressionado() 
{
    return second_botao_boot.fell();
}

bool estado_botaointerno() {
  return second_botao_boot.read();
}

bool estado_botaoexterno() {
  return botao_boot.read();
  Serial.print(estado_botaoexterno());
}

