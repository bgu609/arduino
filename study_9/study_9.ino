int Ground = 22;
int Vcc = 24;
int Signal = 26;
int var = 0;

int led_Ground = 52;
int led_Red = 50;

void setup() {
  Serial.begin(9600);

  pinMode(Ground, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(Signal, INPUT_PULLUP);
  pinMode(led_Ground, OUTPUT);
  pinMode(led_Red, OUTPUT);

  digitalWrite(Ground, LOW);
  digitalWrite(Vcc, HIGH);
  digitalWrite(led_Ground, LOW);
  digitalWrite(led_Red, LOW);
}

void loop() {
  var = digitalRead(Signal);
  
  if(!var) {
    digitalWrite(led_Red, HIGH);
    Serial.println(var, DEC);
  }
  else {
    digitalWrite(led_Red, LOW);
  }
  
  delay(100);
}
