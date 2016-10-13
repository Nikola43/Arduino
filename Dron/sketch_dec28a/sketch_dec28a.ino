#define IZQ 3
#define DER 5

int M1 = 0, M2 = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(IZQ, OUTPUT);
  pinMode(DER, OUTPUT);
}

void loop() 
{
  int x;
  for( x = 0; x < 255; x++ )
  {
      analogWrite(IZQ, x);
      Serial.println(x);
      
      delay(20);
  }
  for( x = 255; x > 0; x-- )
  {
      analogWrite(IZQ, x);
      Serial.println(x);
      
      delay(20);
      
  }

    for( x = 0; x < 255; x++ )
  {
      analogWrite(DER, x);
      Serial.println(x);
      
      delay(20);
  }
  for( x = 255; x > 0; x-- )
  {
      analogWrite(DER, x);
      Serial.println(x);
      
      delay(20);
      
  }

  

}
