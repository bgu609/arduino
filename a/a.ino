int sig = 22;

void setup() {
  pinMode(sig, OUTPUT);
  digitalWrite(sig, LOW);

}

void loop() {
  digitalWrite(sig, HIGH);
  delay(3000);
  digitalWrite(sig, LOW);
  delay(3000);
}
