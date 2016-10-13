/*
  SD card read/write
  
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10

 1. VCC
 2. GND
 3. MISO 12
 4. CS   10
 5. MOSI 11
 6. CLK  13
 */

#include <SPI.h>
#include <SD.h>

#define CS 53

File myFile;

void setup()
{
    //Inicializamos comunicacion serie
    Serial.begin(9600);

    //Inicializamos SD
    Serial.print("Inicializando SD... ");
    if (!SD.begin(CS)) 
        Serial.println("ERROR");
    else
        Serial.println("OK");

    //Creamos y abrimos un archivo en modo escritura
    myFile = SD.open("prueba.txt", FILE_WRITE);

    //Si se ha creado y abierto el fichero el fichero escribimos en el
    if (myFile) 
    {
        Serial.print("Escribiendo en el fichero: "); Serial.println(myFile);
        myFile.println("testing 1, 2, 3.");
       
        // close the file:
        myFile.close();
        Serial.println("Escritura realizada correctamente.");
    } 

}


void loop()
{
  // nothing happens after setup
}


