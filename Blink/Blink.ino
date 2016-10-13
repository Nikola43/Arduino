/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led  = 13;
int val = 0;

// the setup routine runs once when you press reset:
void setup()
{   
  Serial.begin(9600);
  Serial.println("init");  
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
}

// the loop routine runs over and over again forever:
void loop() 
{
  if (Serial.available() > 0) 
      val = Serial.read();
      
  if(val == 'H')
  {
      int i; 
      for(i=0; i<5; i++);
      {
          digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
          Serial.println("HIGH");
          delay(500);
          digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
          Serial.println("LOW\n");
          delay(500);
      }
  }
  else if(val == 'L')
  {
          digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
          Serial.println("LOW\n");
  }
}
