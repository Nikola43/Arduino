

char datos = 4;

void setup() 
{
   //Iniciamos la comunicacion del puerto serie
   Serial.begin(9600);
   Serial.println("Iniciando arduino..");
   pinMode(13, OUTPUT);
}

void loop() 
{
    if ( Serial.available() )
    {
        datos = Serial.read();
    }
    if ( datos == '1' )
    {
      digitalWrite(13, HIGH);
    }
    if ( datos == '2' )
    {
      digitalWrite(13, LOW);
    }
    Serial.write('P');

    
}
