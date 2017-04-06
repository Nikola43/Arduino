#include <Sprite.h>  // Sprite before Matrix
#include <Matrix.h>

#define CLK 7
#define CS 6
#define DIN 5
#define NUM_CHIPS 2

/*  
   Configuracion pines
   
   pin 5: dataInput   (DIN)
   pin 6: chipSelect  (CS)
   pin 7: clock       (CLK)
*/

//                  DIN, CLK, LOAD, #chips
Matrix myLeds = Matrix(5, 7, 6);

Sprite letter_L = Sprite(5, 8,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11111,
  B11111
);
Sprite letter_E = Sprite(5, 8,
  B11111,
  B11111,
  B11000,
  B11110,
  B11110,
  B11000,
  B11111,
  B11111
);
Sprite letter_D = Sprite(6, 8,
  B111100,
  B111110,
  B110111,
  B110011,
  B110011,
  B110111,
  B111110,
  B111100
);
Sprite letter_S = Sprite(5, 8,
  B01110,
  B11111,
  B11000,
  B11110,
  B01111,
  B00011,
  B11111,
  B01110
);

void setup() {
  myLeds.clear();
  myLeds.setBrightness(4);

}

void loop() {
    myLeds.write(0, 0, letter_L);

}

