/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 6;
int greenPin = 5;
int bluePin = 3;

//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

int redValue = 20;
int redDirection = 1;

int greenValue = 80;
int greenDirection = 0;

int blueValue = 60;
int blueDirection = 1;

int minValue = 0;
int maxValue = 120;

void loop()
{
  if (redDirection == 1) { redValue++; } else { redValue--; }
  if (redValue > maxValue) { redValue = maxValue; redDirection = 0; }  
  if (redValue < minValue) { redValue = minValue; redDirection = 1; }

  if (greenDirection == 1) { greenValue++; } else { greenValue--; }
  if (greenValue > maxValue) { greenValue = maxValue; greenDirection = 0; }  
  if (greenValue < minValue) { greenValue = minValue; greenDirection = 1; }

  if (blueDirection == 1) { blueValue++; } else { blueValue--; }
  if (blueValue > maxValue) { blueValue = maxValue; blueDirection = 0; }  
  if (blueValue < minValue) { blueValue = minValue; blueDirection = 1; }

  setColor(redValue, greenValue, blueValue);
  
  delay(20);
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
