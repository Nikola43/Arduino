int rele = 13;
int sensorSonido = 6;
int intervaloLectura = 100;
int lecturaSensor = 0;
int estadoRele = 0;

unsigned long momentoEventoAnterior = 0;

void setup()
{
    Serial.begin(19200);//Velocidad del puerto serial
    pinMode(sensorSonido,INPUT);//configura el pin 2 como entrada
    pinMode(rele, OUTPUT);// configura el pin 13 como salida
}

 
void loop()
{
    lecturaSensor = digitalRead(sensorSonido);
    
    if (lecturaSensor == HIGH)
    {   
       unsigned long momentoEventoActual = millis();
       
       if ((unsigned long)(momentoEventoActual - momentoEventoAnterior) >= intervaloLectura) 
       {
          Serial.print("\tActual: ");
          Serial.print(momentoEventoActual);

          Serial.print("\tAnterior: ");
          Serial.print(momentoEventoAnterior);

          Serial.print("\tDiferencia: ");
          Serial.println(momentoEventoActual - momentoEventoAnterior);

          if ( (momentoEventoActual - momentoEventoAnterior) < 400 )
          {
              estadoRele = !estadoRele;
          }
          
          momentoEventoAnterior = momentoEventoActual;
       }
    digitalWrite(rele, estadoRele);
    }
 }
