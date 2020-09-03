int sw_ground = 22;
int Vcc = 24;
int sw_sig = 26;

int Blue = 40;
int Green = 42;
int Red = 44;
int led_ground = 46;

void setup() {
  pinMode(sw_ground, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(sw_sig, INPUT_PULLUP);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(led_ground, OUTPUT);
  
  digitalWrite(sw_ground, LOW);
  digitalWrite(Vcc, HIGH);
  digitalWrite(Blue, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Red, LOW);
  digitalWrite(led_ground, LOW);
  
  Serial.begin(9600);
}

void loop() {
  if(!digitalRead(sw_sig) && Red==LOW && Green==LOW && Blue==LOW) {
    Serial.println("Pushed");
    digitalWrite(Red, HIGH);
    delay(500);
  }
  else if(!digitalRead(sw_sig) && Blue==HIGH){
    Serial.println("Pushed");
    digitalWrite(Blue, LOW);
    delay(500);
  }
  else if(!digitalRead(sw_sig) && Green==HIGH){
    Serial.println("Pushed");
    digitalWrite(Green, LOW);
    digitalWrite(Blue, HIGH);
    delay(500);
  }
  else if(!digitalRead(sw_sig) && Red==HIGH){
    Serial.println("Pushed");
    pinMode(Red, OUTPUT);
    digitalWrite(Green, HIGH);
    delay(500);
  }
}
