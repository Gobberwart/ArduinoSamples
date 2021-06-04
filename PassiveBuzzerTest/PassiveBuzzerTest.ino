int pinBuzzer=31;
int delayTimeMicroseconds=0;
int incrementVal=12;
int minVal=1000;
int maxVal=3000;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinBuzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (delayTimeMicroseconds=minVal; delayTimeMicroseconds<=maxVal; delayTimeMicroseconds += incrementVal) {
    digitalWrite(pinBuzzer,HIGH);
    delayMicroseconds(delayTimeMicroseconds);
    digitalWrite(pinBuzzer,LOW);
    delayMicroseconds(delayTimeMicroseconds);
  }

  for (delayTimeMicroseconds=maxVal; delayTimeMicroseconds>=minVal; delayTimeMicroseconds -= incrementVal) {
    digitalWrite(pinBuzzer,HIGH);
    delayMicroseconds(delayTimeMicroseconds);
    digitalWrite(pinBuzzer,LOW);
    delayMicroseconds(delayTimeMicroseconds);
  }
}
