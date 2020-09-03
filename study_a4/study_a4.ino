int Blue = 7;
int Green = 6;
int Red = 5;
int Ground = 4;

double val = 0;

int senGround = A0;
int senVcc = A1;
int senSignal = A2;

int sigInput = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Ground, OUTPUT);

  pinMode(senGround, OUTPUT);
  pinMode(senVcc, OUTPUT);
  pinMode(senSignal, INPUT);

  digitalWrite(Blue, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Red, LOW);
  digitalWrite(Ground, LOW);

  digitalWrite(senGround, LOW);
  digitalWrite(senVcc, HIGH);
}

void loop() {
  /*
  for(int i=5;i<128;i++) {
    analogWrite(Blue, i);
    delay(20);
  }
  for(int i=128;i>=5;i--) {
    analogWrite(Blue, i);
    delay(20);
  }
  */
  
  for(int i=0; i<=200; i++) {
    sigInput = analogRead(senSignal);
    Serial.println(sigInput);
    
    val = sin(i*3.14/100-0.5*3.14);
    analogWrite(Blue, (val+1)*100);
    delay(40);
  }
}
