// Tutorial on DIY TECH TUBE https://youtu.be/gQ3qVFU4RZk
#include <FastLED.h>

int r=100;
int g=0;
int b=0;

#define LED_PIN     4
#define SENSOR_PIN  8
#define NUM_LEDS    30// Enter Number of LEDS

CRGB leds[NUM_LEDS];
CRGB led[NUM_LEDS];
int s=0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
  for (int i = 29; i >= 0; i--){
    leds[i] = CRGB ( r,g,b);
    leds[29-i] = CRGB (r,g,b );
    delay(40);
    FastLED.show();
  }
  
  pinMode(SENSOR_PIN,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  s=digitalRead(SENSOR_PIN);
  Serial.println(s);

  if (s == LOW) {
    leds[14]=CRGB (20, 135, 217);
    leds[15]=CRGB (20, 135, 217);
  } else {
    leds[14] = CRGB ( r,g,b);
    leds[15] = CRGB ( r,g,b);
  }
  
  for (int i = 0; i <= 14; i++) {
     leds[i] = leds[i+1];
     leds[29-i] = leds[28-i];
  }
  
  FastLED.show();
  delay(30);
 
}
