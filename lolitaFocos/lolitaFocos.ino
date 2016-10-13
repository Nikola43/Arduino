    #include <Adafruit_NeoPixel.h>
    #ifdef __AVR__
      #include <avr/power.h>
    #endif
    
    #define PIN 3
    #define NUM_LEDS 5
    
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
    String nombreModoActual;
    
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
    
    
    void setup() 
    {
      // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
      #if defined (__AVR_ATtiny85__)
        if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
      #endif
      // End of trinket special code
    
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
            case 11: blanco_parpadeo(); break;
            case 10: rojo(); break;
            case 9:  verde(); break;
            case 8:  azul(); break;
            case 7:  amarillo(); break;
            case 6:  naranja(); break;
            case 5:  rojo_parpadeo(); break;   
            case 4:  fade_colores(); break;
            case 2:  off(); break;   
        }
        strip.show();
        Serial.print("Modo Seleccionado: "); Serial.print(modoActual); Serial.print(" "); Serial.print(nombreModoActual);  Serial.print("\tTecla pulsada: "); Serial.println(teclaPulsadaActualmente);

    }
    
    void blanco()
    {
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(255, 255, 255));
        }
    }
    
    void blanco_parpadeo()
    {
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(255, 255, 255));
            strip.show();
        }
        delay(400);
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(0, 0, 0));
            strip.show();
        }
        delay(400);
    }
    
    void rojo()
    {
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(255, 0, 0));
        }
    }
    
    void verde()
    {
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(0, 255, 0));
        }
    }
    
    void azul()
    {
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(0, 0, 255));
        }
    }

    void amarillo()
    {
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(0x00, 0xFF, 0xE2));
        }
    }

    void naranja()
    {
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(0xFF, 0x80, 0x00));
        }
    }
  
  
    
    
    void off()
    {
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(0, 0, 0));
        }
    }
    
    void fade_colores()
    {
        rainbow(20);
    }
    
    void rojo_parpadeo()
    {
        for( int i = 0; i < NUM_LEDS; i++)
        {
            strip.setPixelColor(i, strip.Color(0xFF, 0, 0xDE));
            strip.show();
        }
    }
    
   
    
    // Fill the dots one after the other with a color
    void colorWipe(uint32_t c, uint8_t wait) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
      }
    }
    
    void rainbow(uint8_t wait) 
    {
      uint16_t i, j;
    
      for(j=0; j<256; j++) 
      {
        for(i=0; i<strip.numPixels(); i++) 
        {
          strip.setPixelColor(i, Wheel((i+j) & 255));
        }
        strip.show();
        delay(wait);
        teclaPulsadaActualmente = leerTeclas();
      }
    }
    
    // Slightly different, this makes the rainbow equally distributed throughout
    void rainbowCycle(uint8_t wait) 
    {
      teclaPulsadaActualmente = leerTeclas();
      uint16_t i, j;
    
      for(j=0; j<256*5; j++)
      { // 5 cycles of all colors on wheel
      teclaPulsadaActualmente = leerTeclas();
        for(i=0; i< strip.numPixels(); i++) 
        {
          teclaPulsadaActualmente = leerTeclas();
          strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        }
        teclaPulsadaActualmente = leerTeclas();
        strip.show();
        
        delay(wait);
        teclaPulsadaActualmente = leerTeclas();
      }
    }
    
    //Theatre-style crawling lights.
    void theaterChase(uint32_t c, uint8_t wait) {
      for (int j=0; j<10; j++) {  //do 10 cycles of chasing
        for (int q=0; q < 3; q++) {
          for (int i=0; i < strip.numPixels(); i=i+3) {
            strip.setPixelColor(i+q, c);    //turn every third pixel on
          }
          strip.show();
    
          delay(wait);
    
          for (int i=0; i < strip.numPixels(); i=i+3) {
            strip.setPixelColor(i+q, 0);        //turn every third pixel off
          }
        }
      }
    }
    
    //Theatre-style crawling lights with rainbow effect
    void theaterChaseRainbow(uint8_t wait) {
      for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
        for (int q=0; q < 3; q++) {
          for (int i=0; i < strip.numPixels(); i=i+3) {
            strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
          }
          strip.show();
    
          delay(wait);
    
          for (int i=0; i < strip.numPixels(); i=i+3) {
            strip.setPixelColor(i+q, 0);        //turn every third pixel off
          }
        }
      }
    }
    
    // Input a value 0 to 255 to get a color value.
    // The colours are a transition r - g - b - back to r.
    uint32_t Wheel(byte WheelPos) {
      WheelPos = 255 - WheelPos;
      if(WheelPos < 85) {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
      }
      if(WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
      }
      WheelPos -= 170;
      return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
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
        
        return(pulsada);
    }

