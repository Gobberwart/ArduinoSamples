#define PIN_LED1  2
#define PIN_LED2  3
#define PIN_LED4  4
#define PIN_LED8  5
#define PIN_LED16 6
#define PIN_LED32 7

int waitTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED1,OUTPUT);
  pinMode(PIN_LED2,OUTPUT);
  pinMode(PIN_LED4,OUTPUT);
  pinMode(PIN_LED8,OUTPUT);
  pinMode(PIN_LED16,OUTPUT);
  pinMode(PIN_LED32,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i<=63; i++) {
    int x = i;

    if (x / 32 > 0) digitalWrite(PIN_LED32,HIGH);
    else digitalWrite(PIN_LED32,LOW);
    x = x % 32;
    
    if (x / 16 > 0) digitalWrite(PIN_LED16,HIGH);
    else digitalWrite(PIN_LED16,LOW);
    x = x % 16;
    
    if (x / 8 > 0) digitalWrite(PIN_LED8,HIGH);
    else digitalWrite(PIN_LED8,LOW);
    x = x % 8;

    if (x / 4 > 0) digitalWrite(PIN_LED4,HIGH);
    else digitalWrite(PIN_LED4,LOW);
    x = x % 4;

    if (x / 2 > 0) digitalWrite(PIN_LED2,HIGH);
    else digitalWrite(PIN_LED2,LOW);
    x = x % 2;

    if (x > 0) digitalWrite(PIN_LED1,HIGH);
    else digitalWrite(PIN_LED1,LOW);
    
    delay(waitTime);
  }
}
