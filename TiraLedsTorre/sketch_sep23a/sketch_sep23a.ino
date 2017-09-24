#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 1


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup()
{
    Serial.begin(9600);
    strip.begin();
    strip.show();
}

void loop() 
{
  char* serialInput;

  //Read RGB color from serial port
  if(Serial.available() > 0)
  {
     serialInput = GetSerialString();

     for ( int i = 0; serialInput[i] != '\0'; i++ )
     {
          Serial.println(serialInput[i]);
     }
  }

  //Parse color to r g b variables
  long RGBColor = (long) strtol( &serialInput[1], NULL, 16);
        
  byte red   = RGBColor >> 16;
  byte green = RGBColor >> 8 & 0xFF; 
  byte blue  = RGBColor & 0xFF;
        
  Serial.print("Red: "); Serial.print(red, HEX); Serial.print("  Green: "); Serial.print(green, HEX); Serial.print("  Blue: "); Serial.println(blue, HEX);

  //show color
  strip.setPixelColor(0, red, green, blue);
  strip.show();

}

char* GetSerialString()
{
   char string[256];
   int index = 0;
   
   while(Serial.available() > 0)
   {
       /*Read a character as it comes in:*/
       char byteBuffer = Serial.read(); 

       if(index < 255)
       {
           /*Place the character in the string buffer:*/
           string[index] = byteBuffer;
           string[index + 1] = '\0';
           /*Go to the index to place the next character in:*/
           index++;
       }
   }
   return string;
}
