
#include <IRremote.h>

int RECV_PIN = A0;
int val;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
    if (irrecv.decode(&results))
    {
        val = results.value;
        Serial.println(results.value, HEX);
        irrecv.resume(); // Receive the next value
    }
    
    switch(val)
    {
      case 0xA81 : colorWipe(strip.Color(255, 0, 0), 30); break;
      case 0x281 : colorWipe(strip.Color(255, 0, 0), 30); break;
    }
}
