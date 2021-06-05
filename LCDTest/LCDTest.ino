#include <LiquidCrystal.h>

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

float firstNumber;
float secondNumber;
float result;

String op="+";

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Enter 1st number");
  while(Serial.available() == 0) {
    //do nothing}
  }
  firstNumber = Serial.parseFloat();

  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Enter 2nd number");
  while(Serial.available() == 0) {
    //do nothing}
  }
  secondNumber = Serial.parseFloat();

  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Enter operator");
  lcd.setCursor(0,1);
  lcd.print("+,-,*,/");
  while(Serial.available() == 0) {
    //do nothing}
  }
  op=Serial.readString();

  if(op == "+") {
    result=firstNumber+secondNumber;    
  } else if (op=="-") {
    result=firstNumber-secondNumber;    
  } else if (op=="*") {
    result=firstNumber*secondNumber; 
  } else if (op=="/") {
    result=firstNumber/secondNumber; 
  } else {
    result=0;
  }

  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print(firstNumber);
  lcd.print(op);
  lcd.print(secondNumber);
  lcd.setCursor(0,1);
  lcd.print("=");
  lcd.print(result);

  delay(5000);
}
