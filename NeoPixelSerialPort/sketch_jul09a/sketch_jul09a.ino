#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include <EEPROM.h>

#define PIN 6
#define NUM_LEDS 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.


long colorHexCode;

void setup()
{  
    char EEPROMcolor[6];

    for ( int i = 0; i < 6; i++ )
    {
        EEPROMcolor[i] = EEPROM.read(i);
    }

    colorHexCode = (long) strtol( &EEPROMcolor[0], NULL, 16);

    Serial.begin(9600);
    strip.begin();
    strip.show(); 
}


void loop() 
{
   char color[6];

   char* serialInput = NULL;
   
   if( Serial.available() > 0 )
   {
       serialInput = getSerialString();

       if ( serialInput != NULL )
       {
           for ( int i = 0; i < 6; i++ )
           {
               EEPROM.write(i, serialInput[i]);
           }
           

           for ( int i = 0; i < 6; i++ )
           {
              color[i] = serialInput[i];
           }
           

           colorHexCode = (long) strtol( &color[0], NULL, 16);
           serialInput = NULL;
       }
   }

   
  strip.setPixelColor(0, colorHexCode );
  strip.show();
}

char* getSerialString()
{
   char string[256];
   int index = 0;
   
   while( Serial.available() > 0 )
   {
       char byteBuffer = Serial.read(); 

       if( index < 255 )
       {
           string[index] = byteBuffer;
           string[index + 1] = '\0';
           index++;
       }
   }
   return string;
}
