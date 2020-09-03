int num = 11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  do {
    Serial.println(num);
    num++;
    delay(500);
  } while(num < 10);

  exit(0);
}
