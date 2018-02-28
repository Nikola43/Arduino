//Debug baud rate
#define SERIAL_RATE 9600

void setup()
{
  Serial.begin(SERIAL_RATE);
}

void loop()
{
    midiControlChange(1, 127, 48);
    midiControlChange(1, 127, 48);
}

void midiControlChange(byte channel, byte ccNum, byte value)
{
  //Send a MIDI control change event through USB
  MIDIEvent event = {0x0B, 0xB0 | channel, ccNum, value};
  MIDIUSB.write(event);
  MIDIUSB.flush();
}
