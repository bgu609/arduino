int Ground = 7;
int Signal = 5;
int soundList[] = {262, 294, 330, 349, 392, 440, 494, 524};
int singArray[] = {4,2,2,4,2,0,1,2,1,0,2,4,7,4,7,4,7,4,2,4,1,3,2,1,0};
int dlArray[] = {200,100,100,100,100,200,200,100,100,100,100,200,150,50,100,100,100,100,200,200,100,100,100,100,200};
int slow = 2;
int count = sizeof(singArray)/sizeof(singArray[0]);

void setup() {
  pinMode(Ground, OUTPUT);
  pinMode(Signal, OUTPUT);

  digitalWrite(Ground, LOW);
}

void loop() {
  for(int i=0; i<count; i++) {
    tone(Signal, soundList[singArray[i]]);
    delay(dlArray[i]*slow);
    noTone(Signal);
    delay(50);
  }
  delay(10000);
}
