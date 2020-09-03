int countUp = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  countUp++;
  Serial.println(countUp);
  delay(1000);
}
