#include <IRremote.h>
#define LED 13

//Pin al que va conectado el receptor IR de arduino
int RECV_PIN = A0;

//valor que recibe por ir
int val;

//Objeto para leer y decodificar el codigo
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
    //Iniciamos comunicacion
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver

    //Establecemos el led como salida
    pinMode(LED, OUTPUT);
}

void loop()
{
    //Si lee datos los decodifica y los imprime
    if (irrecv.decode(&results))
    {
        val = results.value;
        Serial.println(results.value, HEX);
        irrecv.resume(); // Receive the next value
    }

    //Segun lo leido enciende o apaga el led conectado a la patilla 13
    switch(val)
    {
      case 0x8808A46 : digitalWrite(LED, HIGH); break;
      case 0x8808B47 : digitalWrite(LED, LOW); break;
    }
}
