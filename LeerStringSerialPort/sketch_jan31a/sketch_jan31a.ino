int interval;

void setup()
{
    Serial.begin(9600);
}

void loop() {
    
  if(Serial.available() > 0)
  {
     char* serialInput = GetSerialString();
     interval = atoi(serialInput);
     Serial.print("LED interval is now ");
     Serial.println(interval,DEC);
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
           /*Go to the index to place the next character in:*/
           index++;
       }
   }
   
   string[255] = '\0'; //Null-terminate the string;
   
   return string;
}

