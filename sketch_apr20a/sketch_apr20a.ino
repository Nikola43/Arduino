

char datos = 4;

void setup() 
{
   //Iniciamos la comunicacion del puerto serie
   Serial.begin(9600);
   Serial.println("Iniciando arduino..");
}

void loop() 
{
    if ( Serial.available() )
    {
        datos = Serial.read();
        Serial.println(datos);
    }

    
}
