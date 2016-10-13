
#include <Adafruit_NeoPixel.h>

#define STRIP_PIN     2
#define NUM_LEDS     48
#define DELAY_TIME   500

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, STRIP_PIN, NEO_GRB + NEO_KHZ800);

// Initialize color variables
int redVal = 0, greenVal = 0, blueVal = 0;

void setup()
{
    pixels.begin();
    Serial.begin(9600);
}

void loop()
{
    redVal = 127;

    int x;
    for (x = 0; x < NUM_LEDS; x++)
    {

      pixels.setPixelColor(x, pixels.Color(redVal, greenVal, blueVal));
      pixels.setPixelColor(x - 1 , pixels.Color(0, 0, 0));
      pixels.show();
    
      delay(DELAY_TIME);
    }
}
        
