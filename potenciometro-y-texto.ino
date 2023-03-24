# servos
practicas
#include <Servo.h>

//Pin de control do servo
#define CTRL 3

//Pin de lectura do potenc
#define POT A5

//Declaramos o obxecto motor
//da clase Servo
Servo motor;
int angulo = 0;
int veloc = 125;

String orde ="";
int posicion = 0;

void setup() {
  motor.attach(CTRL);
  Serial.begin(9600);
}

void loop() {
  if(angulo = analogRead(POT)){
  angulo = map(angulo, 0, 1023, 0, 180);
  //Actualiza servo
  motor.write(angulo);
  delay(veloc);
  }
  else(Serial.available()); {
    orde = Serial.readStringUntil('\n');
    orde.toLowerCase();
    if(orde.equals("esquerda")) posicion = 180;
    else if(orde.equals("dereita")) posicion = 0;
    else if(orde.equals("centro")) posicion = 90;
    else {
      int tmp = orde.toInt();
      if(tmp >= 0 && tmp <= 180) posicion = tmp;
      else posicion = 0;
      
       motor.write(posicion);
  delay(veloc);

    }
  }
}
