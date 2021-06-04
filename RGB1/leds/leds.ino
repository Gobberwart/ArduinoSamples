/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 6;
int greenPin = 5;
int bluePin = 3;
int ledOnboard = 13;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

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
  for (int redValue = 100; redValue <= 255; redValue +=10) {
    int greenValue = int(redValue * 0.3);
    int blueValue = int(redValue * 0.1);

    #ifdef DEBUG
    Serial.println(redValue);
    Serial.println(greenValue);
    Serial.println(blueValue);
    #endif
    
    setColor(redValue,greenValue,blueValue);
    //setColor(0,redValue,0);
    //setColor(0,0,redValue);
    //setColor(redValue,5,1);
    if (random(10) >= 7) redValue=100;
    delay(150);
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
