int pinButton=4;
int pinButton2=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinButton,INPUT_PULLUP);
  pinMode(pinButton2,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valButton=digitalRead(pinButton);
  //Serial.println(valButton);
  
  int valButton2=digitalRead(pinButton2);
  Serial.print(valButton);
  Serial.print(",");
  Serial.println(valButton2);
}
