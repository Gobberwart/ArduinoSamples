#define SENSOR_PIN  8
int s=0;

void setup() {  
  pinMode(SENSOR_PIN,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  s=digitalRead(SENSOR_PIN);
  Serial.println(s);
}
