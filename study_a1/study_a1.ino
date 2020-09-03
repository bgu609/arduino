int Vcc = 24;
int Out = 26;
int Ground = 28;

int var = 0;

void setup() {
  Serial.begin(9600);

  pinMode(Vcc, OUTPUT);
  pinMode(Out, INPUT_PULLUP);
  pinMode(Ground, OUTPUT);

  digitalWrite(Vcc, HIGH);
  digitalWrite(Ground, LOW);
}

void loop() {
  var = digitalRead(Out);
  Serial.println(var);
  
  delay(100);
}
