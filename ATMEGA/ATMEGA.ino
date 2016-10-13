#include <stdlib.h>

typedef struct LDR
{
	int   PIN;
        int   LED;
	int   VAL;
	float VOL;
        int   VLED;
	int   SIZE;

};

LDR LDR1 = {A0, 13, 0, 0, 0, 0};

void setup()
{
    /* add setup code here */
	Serial.begin(9600);
	Serial.println("init");
	pinMode(LDR1.PIN, INPUT);
        pinMode(LDR1.LED, OUTPUT);
}

void loop()
{
	LDR1.VAL = analogRead(LDR1.PIN);
	LDR1.VOL = (LDR1.VAL * 5.0) / 1024.0;
	LDR1.SIZE = sizeof(LDR1.VAL);

        LDR1.VLED = map(LDR1.VAL, 0, 1023, 0, 255);
        analogWrite(LDR1.LED, LDR1.VLED);

  /* add main program code here */
	Serial.print(LDR1.PIN);  Serial.print("\t");
        Serial.print(LDR1.LED);  Serial.print("\t");
	Serial.print(LDR1.VAL);  Serial.print("\t");
	Serial.print(LDR1.VOL);  Serial.print("\t");
        Serial.print(LDR1.VLED); Serial.print("\t");
	Serial.println("\n");

}
