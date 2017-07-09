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

void setup()
{
    Serial.begin(9600);
    strip.begin();
    strip.show();
}


void loop() 
{
   char* serialInput;
   
   if(Serial.available() > 0)
   {
     serialInput = GetSerialString();
     
     EEPROM.write(0, '0');
     EEPROM.write(1, 'x');
     EEPROM.write(2, serialInput[0]);
     EEPROM.write(3, serialInput[1]);
     EEPROM.write(4, serialInput[2]);
     EEPROM.write(5, serialInput[3]);
     EEPROM.write(6, serialInput[4]);
     EEPROM.write(7, serialInput[5]);
  }

  for (int i = 0; i < 8; i++)
  {
    Serial.println(EEPROM.read(i));
  }


  char color[] {0,0,0,0,0,0,0,0};

  color[0] = EEPROM.read(0);
  color[1] = EEPROM.read(1);
  color[2] = EEPROM.read(2);
  color[3] = EEPROM.read(3);
  color[4] = EEPROM.read(4);
  color[5] = EEPROM.read(5);
  color[6] = EEPROM.read(6);
  color[7] = EEPROM.read(7);


  unsigned long number = (unsigned long) strtol(color, NULL, 0);

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
           string[index + 1] = '\0';
           /*Go to the index to place the next character in:*/
           index++;
       }
   }
   return string;
}
