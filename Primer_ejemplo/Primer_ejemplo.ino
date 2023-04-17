void setup() {
  // put your setup code here, to run once:
  pinMode(52, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
   

}

void loop() {
  // put your main code here, to run repeatedly:
   int boton = digitalRead(52);
   if(boton == 1){
    digitalWrite(LED_BUILTIN, HIGH);

    
   }else{ 
    digitalWrite(LED_BUILTIN, LOW);
   }

}
