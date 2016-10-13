#define LDR  A1
#define RELE 13
#define SPK  12
#define LM35 A0
#define NOTE_B0  31

float tempC;
float tempF;
float LdrVal;

void setup ()
{
  
    Serial.begin(9600);
    pinMode(RELE, OUTPUT);
    pinMode(SPK,  OUTPUT);
    pinMode(LM35, INPUT);
    pinMode(LDR, INPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
}

    
void loop() 
{
    LdrVal = analogRead(LDR);
    tempC = analogRead(LM35);
    tempC = 5.0 * tempC * 100.0 / 1024.0;
    tempF = ((1.8) * tempC) + 32;
  
    if(LdrVal > 500)
    {
        digitalWrite(2, HIGH);     
    }
    else
        digitalWrite(2, LOW);
  
    if(tempC > 70)
    {
        digitalWrite(RELE, HIGH);
        Serial.println("Desconexion por sobrecaletamiento");
        tone(SPK, 32 , 1000);
        noTone(8);  
        digitalWrite(3, HIGH);   
    }
    else
    {
        digitalWrite(RELE, LOW);
        Serial.print("Celsius: "); Serial.print(tempC); Serial.print("\t");
        Serial.print("Fahrenheit: "); Serial.print(tempF);
        Serial.print(" LUX: "); Serial.println(LdrVal);
        digitalWrite(3, LOW);
    }
    delay(500);
}
