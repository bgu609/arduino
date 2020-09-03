char sw = '0';
int ground =46;
int RED = 42;
int GREEN = 44;

void setup() {
  Serial.begin(9600);
  
  pinMode(31, OUTPUT);
  pinMode(ground, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  digitalWrite(31, LOW);
  digitalWrite(ground, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
}

void loop() {
  int val = 9999;
  val = Serial.read();
  if(val){
    if(val == '1')
    {
      digitalWrite(31, HIGH);
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
    }
    else if(val == '0')
    {
      digitalWrite(31, LOW);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
    }
  }
  
  
}
