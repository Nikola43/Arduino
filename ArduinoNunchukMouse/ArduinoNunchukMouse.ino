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

ArduinoNunchuk nunchuk = ArduinoNunchuk();

boolean mouseIsActive = false;    // whether or not to control the mouse
int lastSwitchState = LOW;        // previous switch state

  // read and scale the two axes:
  int xReading;
  int yReading;
  
  int responseDelay = 5; 

void setup()
{
  Serial.begin(9600);
  while (!Serial) ;
  nunchuk.init();
 // take control of the mouse:
  Mouse.begin();
    Keyboard.begin();
  pinMode(2,INPUT);
  mouseIsActive = !mouseIsActive;
}

void loop()
{  
  chuckRead();
  xReading = readAccelX();
  yReading = readAccelY();
 
   readAnalogY();
   readAnalogX();   

  // if the mouse control state is active, move the mouse:
  if (mouseIsActive)
  { 
    Mouse.move(xReading, yReading, 0);
    Serial.print(xReading, DEC);    Serial.println(yReading, DEC);
    
  }  

  // read the mouse button and click or not click:
  // if the mouse button is pressed:
  if (nunchuk.cButton == 1) 
  {
    if (!Mouse.isPressed(MOUSE_LEFT)) 
    {
      Mouse.press(MOUSE_LEFT); 
    }
  }
  else 
  {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT))
    {
      Mouse.release(MOUSE_LEFT); 
    }
  }
  
  
  
  if (nunchuk.zButton == 1) 
  {
    if (!Mouse.isPressed(MOUSE_RIGHT)) 
    {
      Mouse.press(MOUSE_RIGHT); 
    }
  }
  else 
  {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_RIGHT))
    {
      Mouse.release(MOUSE_RIGHT); 
    }
  }

  delay(responseDelay);
  
}

int readAccelX() 
{ 
  int reading = nunchuk.accelX;
  reading = map(reading, 320, 720, -20, 21);
  return reading;
}
int readAccelY() 
{ 
  int reading = nunchuk.accelY; 
  reading = map(reading, 320, 720, -20, 21);
  return reading;
}

void readAnalogX() 
{ 
  int reading = nunchuk.analogX;
  reading = map(reading, 25, 220, -20, 21);
  
  if(reading > 5)
    Keyboard.write('d');
    
  if(reading < -5)
    Keyboard.write('a');
}
void readAnalogY() 
{ 
  int reading = nunchuk.analogY; 
  reading = map(reading, 25, 220, -20, 21);
  
  if(reading > 5)
    Keyboard.write('w');
  if(reading < -5)
    Keyboard.write('s');
  
}

void chuckRead()
{
  nunchuk.update();

  Serial.print(nunchuk.analogX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.cButton, DEC);
}

