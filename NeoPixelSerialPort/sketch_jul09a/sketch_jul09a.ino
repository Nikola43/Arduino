#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUM_LEDS 1

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

int inter;

void loop() 
{
   char* serialInput;
  
   if(Serial.available() > 0)
   {
     serialInput = GetSerialString();
     
     for ( int i = 0; serialInput[i] != '\0'; i++ )
     {
          Serial.println(serialInput[i]);
     }
  }

  char *a = "0x0000ff";

  unsigned long number = (unsigned long) strtol(serialInput, NULL, 0);


  
  strip.setPixelColor(0, number);
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
           //string[index + 1] = '\0';
           /*Go to the index to place the next character in:*/
           index++;
       }
   }
   return string;
}
