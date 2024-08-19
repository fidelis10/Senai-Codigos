#include <ESP32Servo.h>
#include "Atuadores.h"

#define pinServo 27

int angulo = 0;


Servo servoMotor;

void inicializa_servo() {
    servoMotor.attach(pinServo, 500, 2500);
}

void posiciona_servo(int posicao) 
{
    angulo = posicao;
    servoMotor.write(angulo);
}