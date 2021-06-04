#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int servoPin = 9;
int sensorPin = A0;

int minPos = 30;
int maxPos = 150;
int delayTime = 50;
int thresholdVal = 50;

int previousVal = 0;
int sensorVal;
int servoPos;

void setup() {
  pinMode(servoPin,OUTPUT);
  pinMode(sensorPin,INPUT);
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);

  if (sensorVal < previousVal - thresholdVal || sensorVal > previousVal + thresholdVal) {
    servoPos = map(sensorVal,0, 1023, 165, 15);
    myservo.write(servoPos);  
    previousVal = sensorVal;
    delay(delayTime);
  }
}
