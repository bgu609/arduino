int AO = A0;
int Ground = A1;
int Vcc = A2;

int Green = 24;
int Red = 26;
int led_Ground = 28;

int val = 0;

void setup() {
  Serial.begin(9600);

  pinMode(AO, INPUT);
  pinMode(Ground, OUTPUT);
  pinMode(Vcc, OUTPUT);

  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(led_Ground, OUTPUT);
  
  digitalWrite(Ground, LOW);
  digitalWrite(Vcc, HIGH);

  digitalWrite(Green, LOW);
  digitalWrite(Red, LOW);
  digitalWrite(led_Ground, LOW);
}

void loop() {
  val = analogRead(AO);
  
  if(val < 50) {
    digitalWrite(Green, LOW);
    digitalWrite(Red, HIGH);
  }
  else {
    digitalWrite(Red, LOW);
    digitalWrite(Green, HIGH);
  }
}
