#include <IRremote.h>

//Definimos los pines donde van conectados el sensor IR y los reles
const int RELE1 = 2;
const int RELE2 = 3;
const int RECV_PIN = A0;

//Creamos un objeto para inicializar el IR
IRrecv irrecv(RECV_PIN);

//Creamos una variable donde se almacenara el boton recibido en codigo hexadecimal(0x44FB32)
decode_results results;

//En la funcion setup configuramos varios parametros iniciales
void setup()
{
    Serial.begin(9600);       //Iniciamos el puerto serie a una velocidad de 9600 BAUDIOS
    pinMode(RELE1, OUTPUT);   //Establecemos el pin del RELE1 como salida
    pinMode(RELE2, OUTPUT);   //Establecemos el pin del RELE2 como salida
    irrecv.enableIRIn();      //Iniciamos el sensor IR
    irrecv.blink13(true);     //Configuramos que cada vez que reciba datos se encienda el led 13
    digitalWrite(RELE1, LOW); //Inicialmente dejamos en reposo RELE 1
    digitalWrite(RELE2, LOW); //Inicialmente dejamos en reposo RELE 2
}

//En la funcion bucle desarrollamos el funcionamiento de la placa
void loop()
{
    //comprobamos el el sensor recibe datos
    if (irrecv.decode(&results))
    {
        Serial.println(results.value, HEX); //En caso de que SI reciba datos se imprimen los datos en hexadecimal
        irrecv.resume();                    //Despues preparamos el sensor para recibir el siguiente valor
    }
    //Ahora comprobamos el valor recibido y hacemos una cosa u otra segun lo recibido desde el mando
    switch(results.value)
    {
        //Izquierda       //Apagamos RELE2          //Encendemos RELE1
        case 0x73355E0E : digitalWrite(RELE2, LOW); digitalWrite(RELE1, HIGH); break;
        case 0x8581B0C3 : digitalWrite(RELE2, LOW); digitalWrite(RELE1, HIGH); break;
        
        //Derecha         //Apagamos RELE1          //Encendemos RELE2
        case 0x4E32E53A : digitalWrite(RELE1, LOW); digitalWrite(RELE2, HIGH); break;
        case 0xAA84299B : digitalWrite(RELE1, LOW); delay(5); digitalWrite(RELE2, HIGH); break;
        
        //Apagar          //Apagamos RELE1          //Apagamos RELE2
        case 0x28C      : digitalWrite(RELE1, LOW); digitalWrite(RELE2, LOW); break;
        case 0xA8C      : digitalWrite(RELE1, LOW); digitalWrite(RELE2, LOW); break;
    }
}
