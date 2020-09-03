int Ground = 7; int Vcc = 6; int SW = 5; int DT = 4; int Clk = 3;
int ledGnd = 10; int ledRed = 11; int ledGreen = 12; int ledBlue = 13;
int pushGnd = 22; int pushVcc = 24; int pushSig = 26;

int rsvDT = 0; int oldDT = 0;
int rsvClk = 0; int oldClk = 0;
int cnt = 0;

int ledCtl = 0; int ledMode = 1;
int ledBright = 0;

int rotate();
void Led(int ledCtl, int ledMode);

void setup() {
  pinMode(Ground, OUTPUT); pinMode(Vcc, OUTPUT); pinMode(SW, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP); pinMode(Clk, INPUT_PULLUP);
  
  pinMode(ledGnd, OUTPUT);
  pinMode(ledRed, OUTPUT); pinMode(ledGreen, OUTPUT); pinMode(ledBlue, OUTPUT);
  
  pinMode(pushGnd, OUTPUT); pinMode(pushVcc, OUTPUT); pinMode(pushSig, INPUT);
  
  digitalWrite(Ground, LOW); digitalWrite(Vcc, HIGH); digitalWrite(ledGnd, LOW);
  digitalWrite(ledRed, LOW); digitalWrite(ledGreen, LOW); digitalWrite(ledBlue, LOW);
  digitalWrite(pushGnd, LOW); digitalWrite(pushVcc, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  ledCtl = rotate();          // 실시간으로 rotate 변화값을 감지 (-1 or 0 or 1)
  
  if(!digitalRead(pushSig)) {
    ledMode++;                // 버튼 누를 때마다 모드 변경
    ledMode = ledMode%4;      // 나머지 값을 이용해 모드는 0~3을 순환
    Led(ledCtl, ledMode);     // 밝기 변화
    delay(300);               // 모드 선택을 안정적으로 하기 위한 딜레이
    Serial.print("led mode : "); Serial.println(ledMode);
  }
  else {                      // 버튼을 누르지 않으면 모드 변경없이 밝기 변화
    Led(ledCtl, ledMode);     // ledCtl로 밝기를 바꿈
  }
}

int rotate() {                //clock 쓰는데 딜레이 걸면 안 됨 (딜레이로 인해 타이밍이 꼬일 수 있음)
  rsvDT = digitalRead(DT);
  rsvClk = digitalRead(Clk);
  if((rsvDT!=oldDT)||(rsvClk!=oldClk)) {
    if((oldDT==LOW)&&(rsvDT==HIGH)) { 
      if(oldClk==LOW) {
        cnt = 1;              // 시계방향 회전 시 1 신호
      }
      else {
        cnt = -1;             // 반시계방향 회전 시 -1 신호
      }
      Serial.print("led bright : "); Serial.println(ledBright);
    }
    oldDT = rsvDT;
    oldClk = rsvClk;
  }
  else {
    cnt = 0;                  // 변화없을 시 0 신호
  }

  return cnt;
}

void Led(int ledCtl, int ledMode) {
  ledBright += ledCtl * 4;                // ledCtl의 부호에 따라 led 밝기 변화 (변화 속도 x4)
  
  if(ledBright<0) {                   // led 밝기 범위를 0~128로 제한
    ledBright = 0;
  }
  else if(ledBright>128) {
    ledBright = 128;
  }
  
  switch (ledMode) {                  // led 색상 모드에 따른 출력
    case 0:
      digitalWrite(ledRed, LOW); digitalWrite(ledGreen, LOW); digitalWrite(ledBlue, LOW);
      break;
    case 1:
      analogWrite(ledRed, ledBright);
      digitalWrite(ledGreen, LOW); digitalWrite(ledBlue, LOW);
      break;
    case 2:
      analogWrite(ledGreen, ledBright);
      digitalWrite(ledRed, LOW); digitalWrite(ledBlue, LOW);
      break;
    case 3:
      analogWrite(ledBlue, ledBright);
      digitalWrite(ledRed, LOW); digitalWrite(ledGreen, LOW);
      break;
  }
}
