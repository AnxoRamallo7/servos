#include <Servo.h>

//Pin de control do servo
#define CTRL 3

//Pin de lectura do potenciometro
#define POT A5


Servo motor;
int angulo = 0;
int veloc = 125;

String orde ="";

void setup() {
  motor.attach(CTRL);
  Serial.begin(9600);
}

void loop() {
  //primeiro lee a orde do monitor serie(si a hay)
  if(Serial.available()) {
    orde = Serial.readStringUntil('\n');
    orde.toLowerCase(); 
    //se definimos unha posicion para a palabra
    if(orde.equals("esquerda")){angulo = 180;}
    else if(orde.equals("centro")){angulo = 90;}
    else if(orde.equals("dereita")){angulo = 0;}
  
    else {
      int tmp = orde.toInt();
      if(tmp >= 0 && tmp <= 180) angulo = tmp;
      else angulo = 0;
    }
  } 
  else {
    
    //si non hay nada no monitor colocase na posicion do potenciometro
  angulo = analogRead(POT);
  angulo = map(angulo, 0, 1023, 0, 180);
  }

  //move o servo a posicion deseada
  motor.write(angulo);
  delay(200);
  Serial.println(angulo);
  
}
