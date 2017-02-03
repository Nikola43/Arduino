#include "notas.h"
#include "ArduinoCar.h"
#include <SoftwareSerial.h>
#define TXD 4
#define RXD 5
#define SPEAKER 6


SoftwareSerial BTSerial(RXD, TXD); // RX | TX
ArduinoCar * coche = new ArduinoCar();

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

byte cadenaRecibida[2];
int contadorCaracteres = 0;
  
char datosRecibidos = '0';
int datosEnviados = '0';
boolean andar = false ,andarPlus = false, giroDr = false , giroIzq = false , intermitenteIzq = false , intermitenteDr = false;


void setup()
{

  tocarMelodiaEncendido();
	Serial.begin(115200);
	BTSerial.begin(115200);
}

void imprimirCadena(byte cadena[])
{
    int c = 0;
    while ( cadena[c] != '\0' )
    {
      Serial.print(cadena[c]);
      c++;
    } 
    Serial.println();
}

void limpiarCadena(byte cadena[])
{
    int c = 0;
    while ( cadena[c] != '\0' )
    {
      cadena[c] = '\0';
      c++;
    } 
}

void loop()
{
	// Leia la salida del HC-05 and envie al Monitor Serial del Arduino
	if (BTSerial.available())
	{
		datosRecibidos = BTSerial.read();
    Serial.write(datosRecibidos);
    Serial.println();
	}
 
	if ( datosRecibidos != 0 )
	{   

    //AndarPlus
    if(datosRecibidos == 'p' && andar == false)
    {
     coche->marchaAdelantePlus();
      andar = true;
    }

    //Parar
    if(datosRecibidos == 's' && andar == true)
    {
      coche->parar();
      andar = false;
    }

    //MarchaAtras
    if(datosRecibidos == 'x' && andar == false)
    {
      coche->marchaAtras();
      andar = true;
      
    }

    //GiroDerecha
    if(datosRecibidos == 'd' && giroDr == false)
    {
      coche->girarDerecha();
      giroDr = true;
    }

    //GiroIzquierda
    if(datosRecibidos == 'a' && giroIzq == false)
    {
      coche->girarIzquierda();
      giroIzq = true;
    }

    //Parar Giro
    if(giroIzq == true || giroDr == true)
    {
      if(datosRecibidos = 'k')
      {
        coche->pararGiro();
        giroIzq = false;
        giroDr = false; 

        //Parar intermitente si los hay
        if(intermitenteIzq == true || intermitenteDr == true)
        {
          if(intermitenteIzq == true)
          {
            coche->apagarIntermitenteIzquierdo();
          }else
          {
            coche->apagarIntermitenteDerecho();
          }
        }
      }
    }

    //IntermitenteDer
    if{datosRecibidos == 6 )
    {
      coche->encenderIntermitenteDerecho();
    }

    //IntermitenteIzq
    if(datosRecibidos ==  5)
    {
      coche->encenderIntermitenteIzquierdo();
    }

    //Encender Luces
    if(datosRecibidos == 3)
    {
      coche->encenderLucesDelanteras();
    }

    //Apagar Luces
    if(datosRecibidos == 4)
    {
      coche->apagarLucesDelanteras();
    }
    
	}

  delay(1);
  datosRecibidos = 0;
	
}

void tocarMelodiaEncendido()
{
    // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(6, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(6);
  }
}

