#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

// Motor A connections
int enA = 11;
int in1 = 24;
int in2 = 26;

//Entradas 
int potPin = A0;
int horario = 42;
int antihorario = 40;

void setup() {
  Serial.begin(9600);
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 
  pinMode(horario, INPUT);
  pinMode(antihorario, INPUT); 
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sentido: "); 
  lcd.setCursor (0,1);
  lcd.print("Velocidad(%): 00");
}

void loop() {
  directionControl();
  speedControl();
  pantalla();
}

// This function lets you control spinning direction of motors
void directionControl() {
  if (digitalRead(horario) == HIGH) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (digitalRead(antihorario) == HIGH) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}
  
  
// This function lets you control speed of the motors
void speedControl() {
  // For PWM maximum possible values are 0 to 255
  // Read the value of the potentiometer
  int potVal = analogRead(potPin);

  // Map the potentiometer value to a range of 0 to 255
  int speedVal = map(potVal, 0, 1023, 0, 255);

  // Set the motor speed
  analogWrite(enA, speedVal);
  delay(20);
}


//Funcion para la pantalla LED
void pantalla(){
  int potVal = analogRead(potPin);
  int velocidad = map(potVal, 0, 1023, 0, 100);
  
  lcd.setCursor(8,0);
  if (digitalRead(horario) == HIGH) {
    lcd.print("Horario"); 
  } else if (digitalRead(antihorario) == HIGH) {
    lcd.print("Antihorario");
  }
  
  if (velocidad <100){
    lcd.setCursor(13,1);
    lcd.print(' ');
    lcd.print(velocidad);
    lcd.display();
  } else {
  lcd.setCursor(13,1);
  lcd.print(velocidad);
  lcd.cursor_off();
  }
}
