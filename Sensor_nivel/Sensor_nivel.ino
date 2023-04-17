int nivel;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  nivel =  analogRead(A2);
  Serial.println(nivel);
  if (nivel>500){
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(100);


  
}
