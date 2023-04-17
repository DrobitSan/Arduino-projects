#include <Stepper.h>

//Variables
int n1 = 24;
int n2 = 26;
int n3 = 28;
int n4 = 30;

//Objeto motor (pasos por vuelta, n1, n3, n2, n4)
Stepper motor(2048, n1, n3, n2, n4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.setSpeed(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    int grados = Serial.parseInt();
    int pasos = map(grados, 0, 360, 0, 2048);
    motor.step(pasos);
    Serial.println(String(grados) + "º -> " + String(pasos) + "pasos del motor");
  }

}
