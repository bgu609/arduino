int RedPin = 26;
int GreenPin = 24;
int BluePin = 22;
int Ground = 28;

void setup() {
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(Ground, OUTPUT);

  digitalWrite(RedPin, LOW);
  digitalWrite(GreenPin, LOW);
  digitalWrite(BluePin, LOW);
  digitalWrite(Ground, LOW);
}

void loop() {
  digitalWrite(RedPin, HIGH);

  delay(1000);
  
  digitalWrite(RedPin, LOW);
  digitalWrite(GreenPin, HIGH);

  delay(1000);
  
  digitalWrite(GreenPin, LOW);
  digitalWrite(BluePin, HIGH);

  delay(1000);
  
  digitalWrite(BluePin, LOW);
}
