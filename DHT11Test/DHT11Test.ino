#include <DHT.h>
#include <LiquidCrystal.h>

#define Type DHT11

int sensorPin=2;
float humidity;
float tempC;
float tempF;
int startUpTime=500;
int delayTime=1000;

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;


DHT HTSensor(sensorPin,Type);
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HTSensor.begin();
  lcd.begin(16,2);
  delay(startUpTime);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  humidity=HTSensor.readHumidity();
  tempC=HTSensor.readTemperature(false);
  tempF=HTSensor.readTemperature(true);
  */

  humidity=43;
  tempC=23.4;
  tempF=72.9;

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" Temperature: ");
  Serial.print(tempC);
  Serial.print("C/");
  Serial.print(tempF);
  Serial.println("F");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("H: ");
  lcd.print(humidity,1);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("T: ");
  lcd.print(tempC,1);
  lcd.print("C/");
  lcd.print(tempF,1);
  lcd.print("F");

  delay(delayTime);
}
