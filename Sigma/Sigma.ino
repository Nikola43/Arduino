#include <stdlib.h>
#include <SPI.h>
#include <SD.h>
#include <dht.h>

#define DHT11_PIN 2
#define CS 53

char fileName[] = "sigma.txt";

File myFile;

dht DHT;






void setup()
{
    Serial.begin(115200);
    
    Serial.print("Inicializando SD... ");
    if (!SD.begin(CS)) 
        Serial.println("ERROR\n");
    else
        Serial.println("OK\n");
}


void loop() 
{
    leerTemperaturaHumedad();
    leerLecturaSD();
    
    //myFile = SD.open(fileName, FILE_WRITE);
    //SD.remove(fileName);
}

void leerTemperaturaHumedad()
{
    int chk = DHT.read11(DHT11_PIN);
    
    switch (chk)
    {
       case DHTLIB_OK:  /*Serial.print("OK,\t");*/ break;
       case DHTLIB_ERROR_CHECKSUM: Serial.print("Checksum error,\t"); break;
       case DHTLIB_ERROR_TIMEOUT:  Serial.print("Time out error,\t"); break;
       case DHTLIB_ERROR_CONNECT:  Serial.print("Connect error,\t");  break;
       case DHTLIB_ERROR_ACK_L:    Serial.print("Ack Low error,\t");  break;
       case DHTLIB_ERROR_ACK_H:    Serial.print("Ack High error,\t"); break;
       default:                    Serial.print("Unknown error,\t"); break;
    }

    escribirLecturaSD(DHT.temperature, DHT.humidity);
    
    // DISPLAY DATA
    Serial.print(DHT.temperature);
    Serial.print(",");
    Serial.println(DHT.humidity);
    delay(2000);
}

void escribirLecturaSD(int temperatura, int humedad)
{
    char s_temperatura[5], s_humedad[5];
  
    myFile = SD.open(fileName, FILE_WRITE);
    
    if (myFile)
    {
        itoa (temperatura, s_temperatura, 10);
        itoa (humedad, s_humedad, 10);
        

        myFile.print(s_temperatura);
        myFile.print(",");
        myFile.println(s_humedad);
        
        myFile.close();
        Serial.println("\nEscritura realizada correctamente.");
    }
    else
        Serial.println("error opening test.txt");
}


void leerLecturaSD()
{
    myFile = SD.open(fileName);
    if (myFile) 
    {
        while (myFile.available())
            Serial.write(myFile.read());
            
        myFile.close();
        Serial.println("Lectura Finalizada");
        delay(2000);
    } 
    else 
        Serial.println("error opening test.txt");
}

