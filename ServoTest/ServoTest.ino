#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int servoPin = 9;
int minPos = 10;
int maxPos = 170;
int startPos = 90;
int delayTime = 5;
int stepVal = 1;

void setup() {
  pinMode(servoPin,OUTPUT);
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  myservo.write(startPos);
  delay(500);
}

void loop() {
  int i;

  // Sweep from startPos to minPos
  for (i=startPos; i>=minPos; i-=stepVal) {
    myservo.write(mapPos(i));
    delay(delayTime);
  }

  // Sweep from minPos to maxPos
  for (i=minPos; i<=maxPos; i+=stepVal) {
    myservo.write(mapPos(i));
    delay(delayTime);
  }

  // Return to start position (startPos)
  for (i=maxPos; i>=startPos; i-=stepVal) {
    myservo.write(mapPos(i));
    delay(delayTime);    
  }
}

int mapPos(int i) {
  return map(i, 0, 180, 180, 0);
}
