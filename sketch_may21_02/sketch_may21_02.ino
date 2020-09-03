int ledGnd = 4; int ledR = 6; int ledG = 5; int ledB = 7; // led
int SoundGnd = 22; int SoundSig = 26; // 수동 부저
int Alert = 30; // 포토인터럽터
int senSig = A0; int senInput = 0; int senPhase = 0; // 조도센서
double saveR, saveB;
int VRx = A1; int VRy = A2; // 조이스틱

const byte SW = 2; // 인터럽트

int soundList[] = {262, 294, 330, 349, 392, 440, 494, 524}; // 음계 리스트
int MoodMode = 0;
int warn = 0;

int rdX = 0; int rdY = 0;
int valX = 0; int valY = 0;
int stickCtl = 0;

void setup() {
  pinMode(ledGnd, OUTPUT); digitalWrite(ledGnd, LOW);
  pinMode(ledR, OUTPUT); pinMode(ledG, OUTPUT); pinMode(ledB, OUTPUT);
  pinMode(SoundGnd, OUTPUT); digitalWrite(SoundGnd, LOW);
  pinMode(SoundSig, OUTPUT);
  pinMode(Alert, INPUT);
  pinMode(senSig, INPUT);
  pinMode(VRx, INPUT); pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); // PULLUP : 누를시 0
  attachInterrupt(digitalPinToInterrupt(SW),blink,LOW); // 스위치를 누른 상태에서 blink 동작
  
  Serial.begin(9600);
  Serial.println(" ++++ Menu ++++");
  Serial.println("1. Left - Melody");
  Serial.println("2. Right - Moodlight");
  Serial.println("3. Up - Security");
  Serial.println("4. Down - Streetlamp");
  Serial.println("5. push S/W - STOP");
}

int Controller();
void Melody();
void Moodlight();
void Security();
void Streetlamp();

void loop() {
  stickCtl = Controller();        // 조이스틱에 의해 선택 동작
  delay(50);
  switch(stickCtl) {
    case 1:
      digitalWrite(ledR, LOW); digitalWrite(ledG, LOW); digitalWrite(ledB, LOW);
      Melody();
      break;
    case 2:
      digitalWrite(ledR, LOW); digitalWrite(ledG, LOW); digitalWrite(ledB, LOW);
      Moodlight();
      break;
    case 3:
      Security();
      break;
    case 4:
      Streetlamp();
      break;
  }
}

int Controller() {
  rdX = map(analogRead(VRx), 0, 1024, -5, 6);   // 범위를 -5 ~ 5로 매핑
  rdY = map(analogRead(VRy), 0, 1024, -5, 6);

  if(rdX<-1) {          // 좌
    delay(500);
    return 1;
  }
  else if(rdX>1) {      // 우
    delay(500);
    return 2;
  }
  else if(rdY<-1) {     // 상
    delay(500);
    return 3;
  }
  else if(rdY>1) {      // 하
    delay(500);
    return 4;
  }
  else {
    return stickCtl;    // 예외, 이전의 컨트롤값 유지
  }
}

void Melody() {
  int singArray[] = {0,1,2,3,4,5,6,7}; // 악보 리스트
  int dlArray[] = {200,200,200,200,200,200,200,600}; // 음길이 리스트
  int count = sizeof(singArray)/sizeof(singArray[0]); // 소리발생 횟수
  int slow = 2;
  
  for(int i=0; i<count; i++) {          // 악보 연주
    int scan = Controller();            // 반복 중 컨트롤을 조사하여 중단기능
    if(scan!=1) {
      break;
    }
    else {
      tone(SoundSig, soundList[singArray[i]]); // 악보에 저장된 순서에 따라 음계 호출
      delay(dlArray[i]*slow);             // 지정된 시간동안 소리 발생
      noTone(SoundSig);
      delay(50);
    }
  }
  delay(1000);
}

void Moodlight() {
  for(int i=0; i<=200; i++) {               // led 밝기를 총 200단계 변화로 세분화
    int scan = Controller();                // 반복 중 컨트롤을 조사하여 중단기능
    if(scan!=2) {
      digitalWrite(ledR, LOW); digitalWrite(ledG, LOW); digitalWrite(ledB, LOW);
      break;
    }
    else {
      double val = sin(i*3.14/100-0.5*3.14);  // sin함수의 한 주기를 200단계로 나누고, 페이즈를 90도만큼 앞당김
      if(MoodMode==0) {                       // sin값의 최저점을 0으로 만들어 0~200의 밝기단계 구현
       analogWrite(ledR, (val+1)*100);
      }
      else if(MoodMode==1) {
       analogWrite(ledG, (val+1)*100);
      }
      else if(MoodMode==2) {
       analogWrite(ledB, (val+1)*100);
      }
      delay(40);
    }
  }
  MoodMode++;                  // 색상 전환
  MoodMode = MoodMode % 3;     // 색상 모드를 3개로 제한
}

void Security() {
  warn = digitalRead(Alert);    // 센서에서 물체 감지
  int scan = Controller();      // 종료 시 led 끄기
  if(scan!=3) {
    digitalWrite(ledR, LOW); digitalWrite(ledG, LOW); digitalWrite(ledB, LOW);
  }
  else {
     if(warn==HIGH) {              // 감지 상태에서 경보, 적색등 점멸
    tone(SoundSig, soundList[0]);
    digitalWrite(ledR, HIGH); digitalWrite(ledG, LOW); digitalWrite(ledB, LOW);
    delay(200);
    noTone(SoundSig);
    digitalWrite(ledR, LOW);
    delay(200);
    }
    else {                        // 감지 상태가 아니면 무음, 녹색등
      noTone(SoundSig);
      digitalWrite(ledR, LOW); digitalWrite(ledG, HIGH); digitalWrite(ledB, LOW);
    }
  }
}

void Streetlamp() {
  double val;
  senInput = analogRead(senSig);    // 조도 센서에서 외부 밝기 감지
  
  if((senInput >= 200)&&(senPhase == 0)) {      // 페이즈가 0일때 어두워지면
    senPhase = 1;                               // 페이즈를 1로 바꾸고 조명을 서서히 켬
    for(int i=0; i<=100; i++) {
     val = sin(i*3.14/100-0.5*3.14);
     analogWrite(ledR, (val+1)*100);
     analogWrite(ledB, (val+1)*100);
     saveR = (val+1)*100; saveB = (val+1)*100;  // 다른 모드에서 전환 시 조도에 따른 기능 유지를 위해
     delay(20);
    }
  }
  else if((senInput < 200)&&(senPhase == 1)) {  // 페이즈가 1일때 밝아지면
    senPhase = 0;                               // 페이즈를 0으로 바꾸고 조명을 서서히 끈다
    for(int i=100; i<=200; i++) {
      val = sin(i*3.14/100-0.5*3.14);
      analogWrite(ledR, (val+1)*100);
      analogWrite(ledB, (val+1)*100);
      saveR = (val+1)*100; saveB = (val+1)*100;  // 다른 모드에서 전환 시 조도에 따른 기능 유지를 위해
      delay(20);
    }
  }
  else {
    analogWrite(ledR, saveR);    // 저장된 조명을 다시 불러올 수 있음
    analogWrite(ledB, saveB);
    delay(500); // 대기 상태
  }
}

void blink() {
  delayMicroseconds(500);            // 스위치에 의한 blink 동작시 일시정지
}
