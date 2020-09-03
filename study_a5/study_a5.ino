int Blue = 7;
int Green = 6;
int Red = 5;
int Ground = 4;

double val = 0;

int senGround = A0;
int senVcc = A1;
int senSignal = A2;

int sigInput = 0;
int sigPhase = 0;

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
  sigInput = analogRead(senSignal);
  Serial.print(sigInput);

  if((sigInput >= 150)&&(sigPhase == 0)) {
    sigPhase = 1;
    Serial.println(" 야간 모드 ");
    
    for(int i=0; i<=100; i++) {
      val = sin(i*3.14/100-0.5*3.14);
      analogWrite(Blue, (val+1)*100);
      delay(40);
    }
  }
  else if((sigInput < 150)&&(sigPhase == 1)) {
    sigPhase = 0;
    Serial.println(" 야간 모드 해제 ");
    
    for(int i=100; i<=200; i++) {
      val = sin(i*3.14/100-0.5*3.14);
      analogWrite(Blue, (val+1)*100);
      delay(40);
    }
  }
  else {
    Serial.println(" 대기 상태 ");
    delay(3000);
  }
}
