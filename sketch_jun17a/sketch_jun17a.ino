#include <Adafruit_NeoPixel.h>

//Colores fijos
#define BLANCO   12
#define ROJO     11
#define VERDE    10
#define AZUL      9
#define AMARILLO  8
#define NARANJA 7

//Animaciones
#define VERDE_FADE_AMARILLO 6
#define CAMBIO_COLORES 5
#define FADE_COLORES 4
#define ROJO_PARPADEO 2

//Colores fijos
int blancoState = 0;
int rojoState = 0; 
int verdeState = 0; 
int azulState = 0; 
int amarilloState = 0;
int naranjaState = 0; 

//Animaciones
int verdeFadeAmarilloState = 0;
int cambioColoresState = 0; 
int fadeColoresState = 0; 
int rojoParpadeoState = 0; 

//modo 
int modoActual = 0;
int teclaPulsadaActualmente = 0;
String nombreModoActual

Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, 3, NEO_GRB + NEO_KHZ800);

void setup() 
{
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
  
    Serial.begin(9600);
    pinMode(BLANCO, INPUT);
    pinMode(ROJO, INPUT);
    pinMode(VERDE, INPUT);
    pinMode(AZUL, INPUT);
    pinMode(AMARILLO, INPUT);
    pinMode(NARANJA, INPUT);
    pinMode(VERDE_FADE_AMARILLO, INPUT);
    pinMode(CAMBIO_COLORES, INPUT);
    pinMode(FADE_COLORES, INPUT);
    pinMode(ROJO_PARPADEO, INPUT);
}

void loop() 
{

    teclaPulsadaActualmente = leerTeclas();
    
    switch(teclaPulsadaActualmente)
    {
        case 12: modoActual = 12; nombreModoActual = "Blanco"; break;
        case 11: modoActual = 11; nombreModoActual = "Rojo"; break;
        case 10: modoActual = 10; nombreModoActual = "Verde"; break;
        case 9:  modoActual = 9;  nombreModoActual = "Azul"; break;
        case 8:  modoActual = 8;  nombreModoActual = "Amarillo"; break;
        case 7:  modoActual = 7;  nombreModoActual = "Naranja"; break;
        case 6:  modoActual = 6;  nombreModoActual = "Verde Fade Amarillo"; break;
        case 5:  modoActual = 5;  nombreModoActual = "Cambio Colores"; break;
        case 4:  modoActual = 4;  nombreModoActual = "Fade Colores";break;
        case 2:  modoActual = 2;  nombreModoActual = "Rojo Parpadeo";break;
    }
    
    switch(modoActual)
    {
        case 12: blanco(); break;
        case 11: rojo(); break;
        case 10: verde(); break;
        case 9:  azul(); break;
    }
    
    Serial.print("Modo Seleccionado: "); Serial.print(modoActual); Serial.print("\tTecla pulsada: "); Serial.println(teclaPulsadaActualmente);
    delay(100);
}


int leerTeclas()
{
    int pulsada = 0;
  
    blancoState = digitalRead(BLANCO);
    rojoState = digitalRead(ROJO);
    verdeState = digitalRead(VERDE);
    azulState = digitalRead(AZUL);
    amarilloState = digitalRead(AMARILLO);
    
    naranjaState = digitalRead(NARANJA);
    verdeFadeAmarilloState = digitalRead(VERDE_FADE_AMARILLO);
    cambioColoresState = digitalRead(CAMBIO_COLORES);
    fadeColoresState = digitalRead(FADE_COLORES);
    rojoParpadeoState = digitalRead(ROJO_PARPADEO);
    
    delay(1);
    
    if(blancoState == HIGH)
        pulsada = 12;
    
    if(rojoState == HIGH)
        pulsada = 11;
    
    if(verdeState == HIGH)
        pulsada = 10;
        
    if(azulState == HIGH)
        pulsada = 9;
        
    if(amarilloState == HIGH)
        pulsada = 8;
        
      
     if(naranjaState == HIGH)
        pulsada = 7;
    
    if(verdeFadeAmarilloState == HIGH)
        pulsada = 6;
    
    if(cambioColoresState == HIGH)
        pulsada = 5;
        
    if(fadeColoresState == HIGH)
        pulsada = 4;
        
    if(rojoParpadeoState == HIGH)
        pulsada = 2;
    
    delay(1);      
    return(pulsada);
}

void blanco()
{
    for( int i = 0; i < 10; i++)
    {
        strip.setPixelColor(i, strip.Color(255, 255, 255));
        strip.show();
    }
}

void rojo()
{
    for( int i = 0; i < 10; i++)
    {
        strip.setPixelColor(i, strip.Color(255, 0, 0));
        strip.show();
    }
}

void verde()
{
    for( int i = 0; i < 10; i++)
    {
        strip.setPixelColor(i, strip.Color(0, 255, 0));
        strip.show();
    }
}

void azul()
{
    for( int i = 0; i < 10; i++)
    {
        strip.setPixelColor(i, strip.Color(0, 0, 255));
        strip.show();
    }
}






