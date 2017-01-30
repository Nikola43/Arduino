#include "notas.h"
#include "ArduinoCar.h"
#include <SoftwareSerial.h>
#define TXD 4
#define RXD 5

SoftwareSerial BTSerial(RXD, TXD); // RX | TX
ArduinoCar * coche = new ArduinoCar();

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };
  
  
char datosRecibidos = '0';
char datosEnviados = '0';
boolean estaAndando = false;


void setup()
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
    
	Serial.begin(115200);
	BTSerial.begin(115200);
}

void loop()
{
	// Leia la salida del HC-05 and envie al Monitor Serial del Arduino
	if (BTSerial.available())
	{
		Serial.print("Datos Recibidos: ");
		datosRecibidos = BTSerial.read();
		Serial.write(datosRecibidos);
		Serial.println();
	}
	
	// Leia el que  fue  digitado en el Monitor Serial del Arduino y envie al HC-05
	if (Serial.available())
	{
		Serial.print("Datos Enviados: ");
		datosEnviados = Serial.read();
		BTSerial.write( datosEnviados );
		BTSerial.println();
	}
	
	if ( datosRecibidos != 0 )
	{   
            switch(datosRecibidos)
            {
                case '1'  : coche->marchaAdelante(); break;

                
                /*
                case '2'  : coche->coche->parar();   break;
                case '3'  : coche->marchaAtras();    break;
                case '4'  : coche->coche->parar();   break;
                case '5'  : coche->coche->parar();   break;
                case '6'  : coche->coche->parar();   break;
                case '7'  : coche->coche->parar();   break;
                case '8'  : coche->coche->parar();   break;
                case '9'  : coche->coche->parar();   break;
                case '10' : coche->coche->parar();   break;
                case '11' : coche->coche->parar();   break;
                case '12' : coche->coche->parar();   break;
                case '13' : coche->coche->parar();   break;
                case '14' : coche->coche->parar();   break;
                case '15' : coche->coche->parar();   break;
                */
                
            }
	}

  delay(1);
  datosRecibidos = 0;
	
}
