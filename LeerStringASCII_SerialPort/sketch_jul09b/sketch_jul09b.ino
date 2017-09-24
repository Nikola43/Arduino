

void setup()
{
    Serial.begin(9600);
}

void loop() 
{
  char* serialInput;
     
  if(Serial.available() > 0)
  {
     serialInput = GetSerialString();

     for ( int i = 0; serialInput[i] != '\0'; i++ )
     {
          Serial.println(serialInput[i]);
     }
  }

  long RGBColor = (long) strtol( &serialInput[0], NULL, 16);
        
  byte red   = RGBColor >> 16;
  byte green = RGBColor >> 8 & 0xFF; 
  byte blue  = RGBColor & 0xFF;
        
  Serial.print("Red: "); Serial.print(red, HEX); Serial.print("  Green: "); Serial.print(green, HEX); Serial.print("  Blue: "); Serial.println(blue, HEX);

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
