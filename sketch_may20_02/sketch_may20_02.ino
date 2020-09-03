int Signal = 22;
int Vcc = 24;
int Ground = 26;

void setup() {
  pinMode(Signal, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(Ground, OUTPUT);

  digitalWrite(Vcc, HIGH);
  digitalWrite(Ground, LOW);
}

void loop() {
  digitalWrite(Signal, HIGH);
  delay(1000);
  digitalWrite(Signal, LOW);
  delay(1000);
}
