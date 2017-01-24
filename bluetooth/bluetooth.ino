#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11

SoftwareSerial BTSerial(RXD, TXD); // RX | TX

void setup()
{
    Serial.begin(115200);
    BTSerial.begin(115200);  // HC-05 default speed in AT command more
    Serial.println("Introduce un comando AT: ");
}

void loop()
{

  // Leia la salida del HC-05 and envie al Monitor Serial del Arduino 
  if (BTSerial.available())
  {
  	  Serial.write(BTSerial.read());
  }

  // Leia el que  fue  digitado en el Monitor Serial del Arduino y envie al HC-05
  if (Serial.available())
  {
  	  BTSerial.write( Serial.read() );
  }
}
