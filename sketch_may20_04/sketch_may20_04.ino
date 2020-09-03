int Ground = 7;
int Vcc = 6;
int Signal = 5;
int Led = 4;

int sigGet = 0;
int val = 0;

void setup() {
  pinMode(Ground, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(Signal, INPUT);
  pinMode(Led, OUTPUT);
  
  digitalWrite(Ground, LOW);
  digitalWrite(Vcc, HIGH);
  analogWrite(Led, 0);
}

void loop() {
  sigGet = digitalRead(Signal);

  if((sigGet==LOW)&&(val<200)) {
    val++;
    analogWrite(Led, val);
    delay(20);
  }
  else if((sigGet==HIGH)&&(val>0)) {
    val--;
    analogWrite(Led, val);
    delay(20);
  }
}
