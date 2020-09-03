int Ground = A0;
int Vcc = A1;
int VRx = A2;
int VRy = A3;
int SW = A4;

int rdX = 0;
int rdY = 0;
int rdS = 0;

int valX = 0;
int valY = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(Ground, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); // PULLUP : 누를시 0

  digitalWrite(Ground, LOW);
  digitalWrite(Vcc, HIGH);
}

void loop() {
  rdX = map(analogRead(VRx), 0, 1024, -5, 6);
  rdY = map(analogRead(VRy), 0, 1024, -5, 6);
  rdS = digitalRead(SW);
  
  /*
  Serial.print("X: "); Serial.print(rdX); Serial.print("\t\t");
  Serial.print("Y: "); Serial.print(rdY); Serial.print("\t\t");
  Serial.print("["); Serial.print(rdS); Serial.println("]");
  */

  if(rdX>0) {
    valX++;
  }
  else if(rdX<0) {
    valX--;
  }

  if(rdY>0) {
    valY++;
  }
  else if(rdY<0) {
    valY--;
  }

  if(!rdS) {
    valX = 0;
    valY = 0;

    Serial.print("[");
    Serial.print(valX); Serial.print(" , "); Serial.print(valY);
    Serial.println("]");
  }
  else if((rdX!=0)||(rdY!=0)) {
    Serial.print("[");
    Serial.print(valX); Serial.print(" , "); Serial.print(valY);
    Serial.println("]");
  }

  delay(500);
}
