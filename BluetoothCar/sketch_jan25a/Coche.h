// Coche.h

#ifndef _COCHE_h
#define _COCHE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class CocheClass
{
 protected:


 public:
	void init();
};

extern CocheClass Coche;

#endif

