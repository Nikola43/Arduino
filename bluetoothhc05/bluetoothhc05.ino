#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

//#define KEY 7
#define TXD 10
#define RXD 11

SoftwareSerial BTSerial(RXD, TXD); // RX | TX


Adafruit_NeoPixel strip = Adafruit_NeoPixel(7, 6, NEO_GRB + NEO_KHZ800);

#define PIN 6
#define NUM_LEDS 7

String cadenaRecibida;
char caracterRecibido;
char val = ' ';

void setup()
{
    pinMode(3, OUTPUT);
    Serial.begin(9600);
    BTSerial.begin(9600);  // HC-05 default speed in AT command more
    Serial.println("Introduce un comando AT: ");
        strip.begin();
    strip.show();
}

void loop()
{

  // Leia la salida del HC-05 and envie al Monitor Serial del Arduino 
  if (BTSerial.available() > 0)
  {
      val = BTSerial.read();
      Serial.println(val);    
  }

  // Leia el que  fue  digitado en el Monitor Serial del Arduino y envie al HC-05
  if (Serial.available() > 0)
  {
      BTSerial.write(Serial.read());
  }


  if ( val == 'a' )
  {
        strip.setPixelColor(0, 255, 0, 0);
  }
  else if ( val == 'b' )
  {
       strip.setPixelColor(0, 0, 255, 0);
  }
  else if ( val == 'c' )
  {
       strip.setPixelColor(0, 0, 0, 255);
  }
  else
  {
    strip.setPixelColor(0, 0, 0, 0);
  }
  strip.show();
}
