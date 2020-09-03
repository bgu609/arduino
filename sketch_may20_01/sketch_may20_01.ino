int spkGround = 7;
int spkSignal = 5;

int AO = A0;
int Ground = A1;
int Vcc = A2;

int AdcVal = 0;

void setup() {
  pinMode(AO, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);

  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(7, LOW);

  Serial.begin(9600);
}

void loop() {
  delay(250);
  
  AdcVal = analogRead(A0);
  Serial.println(AdcVal);
  
  if(AdcVal > 900) {
    tone(spkSignal, 100);
    delay(500);
    noTone(spkSignal);
  }
  
  delay(250);
}
