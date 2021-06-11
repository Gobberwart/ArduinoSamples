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
int en=8;  //enable
int bl=6;  //backlight on/off. Not very good. Needs a transistor.
int d4=9;
int d5=10;
int d6=11;
int d7=12;


DHT HTSensor(sensorPin,Type); // Create DHT object
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); // Create LCD object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HTSensor.begin();
  lcd.begin(16,2);
  delay(startUpTime); // Allows time for DHT to initalise. Needed?? Testing required.
}

void loop() {
  // put your main code here, to run repeatedly:

  humidity=HTSensor.readHumidity();
  tempC=HTSensor.readTemperature(false);
  tempF=HTSensor.readTemperature(true);


   /*
  // Send info to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" Temperature: ");
  Serial.print(tempC);
  Serial.print("C/");
  Serial.print(tempF);
  Serial.println("F");
  */

  // Send info to LCD
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

  delay(delayTime); // Wait a bit to allow display to update.
}
