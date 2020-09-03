
int KeyVal = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    KeyVal = Serial.read();
    Serial.println(KeyVal, DEC);
  }
}
