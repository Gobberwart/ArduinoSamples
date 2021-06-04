///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: RgbStripSequence
//
// Example to demonstrate how to create an animation sequence for a
// WS2812 RGB LED strip.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-rgbstripseq.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLedRgb.h>

AlaLedRgb rgbStrip;

AlaColor alaPalCats_[] = { 0x000066, 0x666666 };
AlaPalette alaPalCats = { 2, alaPalCats_ };

AlaSeq seq[] =
{
  { ALA_OFF,            1000, 2000, alaPalNull },
  { ALA_ON,             1000, 2000, alaPalCats },
  { ALA_SPARKLE,        1000, 9000, alaPalCats },
  { ALA_CYCLECOLORS,    3000, 6000, alaPalCats },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_FADECOLORSLOOP, 3000, 6000, alaPalCats },
  { ALA_SPARKLE2,       1000, 6000, alaPalCats },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_SPARKLE2,       1000, 6000, alaPalCats },
  { ALA_PIXELSMOOTHSHIFTRIGHT, 6000, 2000, alaPalCats },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_MOVINGBARS,     3000, 6000, alaPalCats },
  { ALA_COMET,          3000, 6000, alaPalCats },
  { ALA_COMETCOL,       3000, 6000, alaPalCats },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_GLOW,           3000, 6000, alaPalCats },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_FIRE,           1000, 6000, alaPalCats },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_BOUNCINGBALLS,  1000, 6000, alaPalCats },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_BUBBLES,        1000, 6000, alaPalCats },
  { ALA_ENDSEQ }
};


void setup()
{
  delay(1000);
  
  rgbStrip.initWS2812(30, 5);
  
  rgbStrip.setBrightness(0x444444);

  rgbStrip.setAnimation(seq);
}

void loop()
{
  rgbStrip.runAnimation();
}
