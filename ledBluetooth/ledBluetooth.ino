#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 7

String cadenaRecibida;
char caracterRecibido;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(7, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
    Serial.begin(9600);
    strip.begin();
    strip.show();
}

void loop() 
{
  

    
        strip.setPixelColor(0, 0, 0, 255);
        strip.setPixelColor(0, 0, 0, 0);

    
    strip.show();
}
