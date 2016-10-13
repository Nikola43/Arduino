/*
 * ArduinoNunchukDemo.ino
 *
 * Copyright 2011-2013 Gabriel Bianconi, http://www.gabrielbianconi.com/
 *
 * Project URL: http://www.gabrielbianconi.com/projects/arduinonunchuk/
 *
 */

#include <Wire.h>
#include <ArduinoNunchuk.h>

#define BAUDRATE 115200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

  // make a string to report a sensor reading:
  char str[80] = {0};
  
char bX[30];
char bY[30];
char bZ[30];

void setup()
{
  Serial.begin(BAUDRATE);
  Serial.println("init");
  nunchuk.init();
    while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
}

void loop()
{
  nunchuk.update();
  
  
  itoa(nunchuk.accelX,bX,10);
  itoa(nunchuk.accelY,bY,10);
  itoa(nunchuk.accelZ,bZ,10);
  
  strcat(str, bX);
  strcat(str, ",");
  
  strcat(str, bY);
  
  Serial.println(str);
  
  int i=0;
  while(str[i] != '\0')
      str[i] = '\0';
}
