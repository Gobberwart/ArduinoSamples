int lightPin=2;
int inbuiltLed=13;

void setup()
{
  pinMode(lightPin, OUTPUT);
  pinMode(inbuiltLed, OUTPUT);
}

void loop()
{
  digitalWrite(inbuiltLed,LOW);
  digitalWrite(lightPin,HIGH);
  delay(2000);
  digitalWrite(lightPin,LOW);
  delay(2000);
}
