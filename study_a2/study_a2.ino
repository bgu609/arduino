int Ground = 22;
int Vcc = 24;
int Signal = 26;

int Green = 48;
int Red = 50;
int led_Ground = 52;

int var = 0;

void setup() {
  Serial.begin(9600);

  pinMode(Ground, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(Signal, INPUT);
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
  var = digitalRead(Signal);
  
  if(var==HIGH) {
    Serial.println("WARNING");
    digitalWrite(Green, LOW);
    digitalWrite(Red, HIGH);
    delay(200);
    digitalWrite(Red, LOW);
  }
  else {
    Serial.println("SAFE");
    digitalWrite(Green, HIGH);
    delay(400);
  }

  delay(200);
}
