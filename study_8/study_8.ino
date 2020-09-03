int Signal = 22;
int Vcc = 24;
int Ground = 26;

void setup() {
  Serial.begin(9600);

  pinMode(Signal, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(Ground, OUTPUT);

  digitalWrite(Signal, LOW);
  digitalWrite(Vcc, HIGH);
  digitalWrite(Ground, LOW);
}

void loop() {
  digitalWrite(Signal, HIGH);
  delay(5000);
  digitalWrite(Signal, LOW);
  delay(1000);
}
