int num = 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(num; num<10; num++) {
    for(int i=1; i<10; i++) {
    Serial.print(num); Serial.print(" X "); Serial.print(i);
    Serial.print(" = "); Serial.println(num*i);
    }
  }
}
