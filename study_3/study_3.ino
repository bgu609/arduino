int countUp = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  count = countUp++;
  Serial.println(count);
  delay(1000);
}
