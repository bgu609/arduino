int Ground = 7;
int Vcc = 6;
int Signal = 5;
int Led = 4;

int sigGet = 0;
double val = 0;
int sigPhase = 0;

void setup() {
  pinMode(Ground, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(Signal, INPUT);
  pinMode(Led, OUTPUT);
  
  digitalWrite(Ground, LOW);
  digitalWrite(Vcc, HIGH);
  digitalWrite(Led, LOW);
}

void loop() {
  sigGet = digitalRead(Signal);

  if((sigGet==0)&&(sigPhase==0)) {
    for(int i=0; i<=100; i++) {
      sigPhase = 1;
      val = sin(i*3.14/100-0.5*3.14);
      analogWrite(Led, (val+1)*100);
      delay(10);
    }
  }
  else if((sigGet==1)&&(sigPhase==1)) {
    for(int i=100; i<=200; i++) {
      sigPhase = 0;
      val = sin(i*3.14/100-0.5*3.14);
      analogWrite(Led, (val+1)*100);
      delay(10);
    }
  }
}
