int interval;

void setup()
{
    Serial.begin(9600);
}

void loop() {
    
  if(Serial.available() > 0)
  {
     char* serialInput = GetSerialString();

     for ( int i = 0; serialInput[i] != '\0'; i++ )
     {
          Serial.println(serialInput[i]);
     }
  }

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
