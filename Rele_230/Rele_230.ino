int rele = 30

void setup() {
  // put your setup code here, to run once:
  pinMode(rele, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rele, HIGH);
  delay(1000);
  Serial.println("Rele encendido");

  digitalWrite(rele, LOW);
  delay(1000);
  Serial.println("Rele apagado");
}
