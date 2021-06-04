const int LED_INBUILT = 13;
const int LED_RED = 5;
const int LED_YELLOW_1 = 6;
const int LED_YELLOW_2 = 3;

void setup() {
  // declare pins to be outputs:
  pinMode(LED_INBUILT, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW_1, OUTPUT);
  pinMode(LED_YELLOW_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED_RED, random(175)+20);
  analogWrite(LED_YELLOW_1, random(175)+80);
  analogWrite(LED_YELLOW_2, random(175)+80);
  delay(random(100));
}
