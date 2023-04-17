int TRIG =  53;
int ECHO = 52;
int DURACION = 0;
int DISTANCIA= 0;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECHO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(200);

  if(DISTANCIA < 100 && DISTANCIA >= 0){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(DISTANCIA * 10);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
