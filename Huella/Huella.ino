#define LED 40 
#define SENSOR 30


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(SENSOR) == HIGH){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
  delay(50); 
}
