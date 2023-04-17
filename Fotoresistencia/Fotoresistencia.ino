int inAnalog = A0;
int valorAnalog = 0; 
int led = LED_BUILTIN;

void setup() {
  Serial.begin(9600); //Sacar por pantalla
  pinMode(led, OUTPUT);

}

void loop() {
  valorAnalog = analogRead(A0);
  Serial.println(valorAnalog);
  delay(10);

  if (valorAnalog > 300){
    digitalWrite(led, HIGH);
    
  }else{
    digitalWrite(led, LOW);
  }

}
