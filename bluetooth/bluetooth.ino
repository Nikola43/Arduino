#include <SoftwareSerial.h>
#define KEY 7
#define TXD 10
#define RXD 11

SoftwareSerial BTSerial(RXD, TXD); // RX | TX

void setup()
{
    Serial.begin(9600);
    BTSerial.begin(38400);  // HC-05 default speed in AT command more
    Serial.println("Introduce un comando AT: ");
}

void loop()
{

  // Leia la salida del HC-05 and envie al Monitor Serial del Arduino 
  if (BTSerial.available())
  {
  	  int a = BTSerial.read();
      Serial.println(a);
  }

  // Leia el que  fue  digitado en el Monitor Serial del Arduino y envie al HC-05
  if (Serial.available())
  {
  	  int b = Serial.read();
      BTSerial.println(b);
  }
}