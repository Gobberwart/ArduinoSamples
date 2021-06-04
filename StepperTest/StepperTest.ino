#include <Stepper.h>

int stepsPerRevolution=2048;
int motorSpeed=10;    // revolutions per minute
int stepVal=5;        // number of steps per loop
int stepDirection=1;  // 1 = clockwise, -1 = counter-clockwise

int buttonPin=2;
int buttonVal;
int lastButtonVal=0;

Stepper myStepper(stepsPerRevolution,8,10,9,11);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop() {
  buttonVal=digitalRead(buttonPin);
  Serial.println(buttonVal);
  if (lastButtonVal==0 && buttonVal==1) stepDirection = -stepDirection;
  lastButtonVal = buttonVal;
  myStepper.step(stepDirection*stepVal);
}
