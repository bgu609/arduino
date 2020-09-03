int AO = A0;
int Ground = A1;
int Vcc = A2;
int DO = A3;

int val = 0;

void setup() {
  pinMode(AO, INPUT);
  pinMode(Ground, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(DO, INPUT);
  
  digitalWrite(Ground, LOW);
  digitalWrite(Vcc, HIGH);

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(DO);
  if(val > 0) {
    Serial.println(val);
    delay(300);
  }
}
