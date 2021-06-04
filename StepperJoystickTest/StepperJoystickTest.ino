#include <Stepper.h>

int stepsPerRevolution=2048;
int stepVal=5;        // number of steps per loop
int stepDirection=1;  // 1 = clockwise, -1 = counter-clockwise
int minSpeed=1;
int maxSpeed=13;

int pinVRX=A1;
int pinVRY=A0;
int pinSwitch=4;
int stepSpeed;

int IN1=8;
int IN2=9;
int IN3=10;
int IN4=11;
Stepper myStepper(stepsPerRevolution,IN1,IN3,IN2,IN4);

void setup() {
  Serial.begin(9600);
  pinMode(pinSwitch,INPUT_PULLUP);
}

void loop() {
  int valX=analogRead(pinVRX);
  int valY=analogRead(pinVRY);
  int valSwitch=digitalRead(pinSwitch);

  if(valX >= 505 && valX <=515) {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  } else {
    if(valX > 515) {
      stepSpeed=map(valX,516,1023,minSpeed,maxSpeed);
      stepDirection=1;
    } else if(valX < 505) {
      stepSpeed=map(valX,0,504,maxSpeed,minSpeed);
      stepDirection=-1;
    }
    myStepper.setSpeed(stepSpeed);
    myStepper.step(stepDirection*stepVal);
  }
   
  Serial.print(valX);
  Serial.print(",");
  Serial.print(valY);
  Serial.print(",");
  Serial.print(valSwitch);
  Serial.print(",");
  Serial.print(stepDirection);
  Serial.print(",");
  Serial.println(stepSpeed);
  
}
