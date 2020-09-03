int Ground = 7;
int Vcc = 6;
int SW = 5;
int DT = 4;
int Clk = 3;

int rsvDT = 0;
int oldDT = 0;
int rsvClk = 0;
int oldClk = 0;
int cnt = 0;

void setup() {
  pinMode(Ground, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(Clk, INPUT_PULLUP);
  
  digitalWrite(Ground, LOW);
  digitalWrite(Vcc, HIGH);

  Serial.begin(9600);
}
//clock 쓰는데 딜레이 걸면 안 됨
void loop() {
  rsvDT = digitalRead(DT);
  rsvClk = digitalRead(Clk);

  if((rsvDT!=oldDT)||(rsvClk!=oldClk)) {
    if((oldDT==LOW)&&(rsvDT==HIGH)) {
      Serial.println(cnt);
      if(oldClk==LOW) {
        cnt += 1;
      }
      else {
        cnt -= 1;
      }
    }
    oldDT = rsvDT;
    oldClk = rsvClk;
  }
}
