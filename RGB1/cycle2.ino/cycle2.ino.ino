/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 6;
int greenPin = 5;
int bluePin = 4;
int ledOnboard = 13;

//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

//uncomment this line to enable serial debug info
//#define DEBUG

void setup()
{
  #ifdef DEBUG 
    Serial.begin(9600);
  #endif
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(ledOnboard, OUTPUT);  
}

void loop()
{
  digitalWrite(ledOnboard,LOW);
  for (int redValue = 0; redValue <= 255; redValue += 5) {
    for (int greenValue = 0; greenValue <= 255; greenValue += 5) {
     for (int blueValue = 0; blueValue <= 255; blueValue += 5) {
        setColor(redValue,greenValue,blueValue);
        delay(25);
      }
    }
  }
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
