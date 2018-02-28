

#include <MIDI.h>  // INlcude MIDI library


void setup() 
{
   MIDI.begin();
}
 
void loop()
{
  MIDI.sendNoteOff(48,127,1);
  delay(1000);
  MIDI.sendNoteOff(48,0,1);
  delay(1000); 
}



