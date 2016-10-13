#include <SoftwareSerial.h>
#define KEY 7
#define TXD 10
#define RXD 11
#define LED 13

SoftwareSerial BTSerial(RXD, TXD); // RX | TX

void fade(char rxD);
void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    BTSerial.begin(9600);  // HC-05 default speed in AT command more
    Serial.println("Introduce un comando AT: ");
}

void loop()
{

  // Leia la salida del HC-05 and envie al Monitor Serial del Arduino 
  if (BTSerial.available())
  {
        char rxD = BTSerial.read();
        fade(rxD);
  }

  // Leia el que  fue  digitado en el Monitor Serial del Arduino y envie al HC-05
  if (Serial.available())
        BTSerial.write(Serial.read());
}

void fade(char rxD)
{
  int brillo = map((int)rxD - 48, 0, 9, 0, 255); //Convertimos char a int y mapeamos los datos
  analogWrite(LED, brillo);
  Serial.print(rxD); Serial.print(" "); Serial.println(brillo);
  delay(30);
}