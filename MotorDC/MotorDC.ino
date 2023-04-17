int speedPin=11;
int dirPin1=24;
int dirPin2=32;
int speedMotor=255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(dirPin1,1);
digitalWrite(dirPin1,0);
analogWrite(speedPin, speedMotor);
}
