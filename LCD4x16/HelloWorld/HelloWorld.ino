/*
  The circuit:

 * LCD VSS pin to GND
 * LCD VDD pin to 5V
 * LCD V0 10k to GND
 * LCD RS pin to digital pin 12
 * LCD RW pin to GND
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD A pin to 5V
 * LCD K pin to GND
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    lcd.begin(20, 4); 
}

void loop() 
{
  int x = 0;
  for(x = 0; x < 20; x++)
  {
    lcd.setCursor(0, 0); 
    lcd.print("Que pasa alvaro");
    
    lcd.setCursor(0, 1); 
    lcd.print("Vamos a fumarnos uno");
    
    lcd.setCursor(0, 2); 
    lcd.print("Y escribiremos "); 
    
    lcd.setCursor(0, 3); 
    lcd.print(x); 
    lcd.setCursor(5, 3);
    lcd.print(" temazos xD "); 
    delay(1000);
    lcd.clear();
  }
}

