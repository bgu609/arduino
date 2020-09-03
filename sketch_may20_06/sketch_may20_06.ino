#include <DHT.h>
#define DHTTYPE DHT11

int Data = 22;
int Vcc = 24;
int Ground = 26;

DHT dht(Data, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(Vcc, OUTPUT);
  pinMode(Ground, OUTPUT);

  digitalWrite(Vcc, HIGH);
  digitalWrite(Ground, LOW);
}

void loop() {
  float fT = dht.readTemperature();
  float fH = dht.readHumidity();
  
  if(isnan(fT)||isnan(fH)) {
    Serial.println("Failed to read from DHT");
    delay(1000);
  }
  else {
    Serial.print("TEMPERATURE : ");
    Serial.print(fT); Serial.print(" [C]\t\t");
    Serial.print("HUMIDITY : ");
    Serial.print(fH); Serial.println(" %");
    delay(1000);
  }
}
