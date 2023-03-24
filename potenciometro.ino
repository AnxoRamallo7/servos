#include <Servo.h>

//Pin de control do servo
#define CTRL 3

//Pin de lectura do potenciometro
#define POT A0

//declaramos que temos un motor concretamente un servo
Servo motor;
int angulo = 0;
int veloc = 100;

void setup() {
  motor.attach(CTRL);
}

void loop() {
  //leemos o valor do potenciometro
  angulo = analogRead(POT);
  angulo = map(angulo, 0, 1023, 0, 180);
  //movemos o servo ao valor do potenciometro
  motor.write(angulo);
  delay(veloc);
}
