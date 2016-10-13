/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Nano w/ ATmega328, Platform=avr, Package=arduino
*/

#define __AVR_ATmega328p__
#define __AVR_ATmega328P__
#define ARDUINO 165
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define F_CPU 16000000L
#define ARDUINO 165
#define ARDUINO_AVR_NANO
#define ARDUINO_ARCH_AVR
extern "C" void __cxa_pure_virtual() {;}

//
//

#include "C:\Arduino\hardware\arduino\avr\variants\eightanaloginputs\pins_arduino.h" 
#include "C:\Arduino\hardware\arduino\avr\cores\arduino\arduino.h"
#include <..\arduinotester\arduinotester.ino>
#include <..\arduinotester\24x32update_bitmaps.h>
#include <..\arduinotester\AutoCheck.c>
#include <..\arduinotester\Battery_check.c>
#include <..\arduinotester\Calibrate_UR.c>
#include <..\arduinotester\CalibrationCap.c>
#include <..\arduinotester\ChargePin10ms.c>
#include <..\arduinotester\CheckPins.c>
#include <..\arduinotester\CheckRotaryEncoder.c>
#include <..\arduinotester\DisplayValue.c>
#include <..\arduinotester\EE_check_init.c>
#include <..\arduinotester\EntladePins.c>
#include <..\arduinotester\GetESR.c>
#include <..\arduinotester\GetFrequency.c>
#include <..\arduinotester\GetIr.c>
#include <..\arduinotester\GetRLmultip.c>
#include <..\arduinotester\GetResistance.c>
#include <..\arduinotester\GetVloss.c>
#include <..\arduinotester\HelpCalibration.c>
#include <..\arduinotester\PinLayout.c>
#include <..\arduinotester\ReadADC.c>
#include <..\arduinotester\ReadBigCap.c>
#include <..\arduinotester\ReadCapacity.c>
#include <..\arduinotester\ReadInductance.c>
#include <..\arduinotester\RefVoltage.c>
#include <..\arduinotester\RvalOut.c>
#include <..\arduinotester\ShowData.c>
#include <..\arduinotester\Transistortester.h>
#include <..\arduinotester\UfAusgabe.c>
#include <..\arduinotester\autoconf.h>
#include <..\arduinotester\bitmaps.h>
#include <..\arduinotester\config.h>
#include <..\arduinotester\font.h>
#include <..\arduinotester\function_menu.c>
#include <..\arduinotester\get_log.c>
#include <..\arduinotester\i2lcd.c>
#include <..\arduinotester\lcd-draw.c>
#include <..\arduinotester\lcd-routines.c>
#include <..\arduinotester\lcd-routines.h>
#include <..\arduinotester\lcd_defines.h>
#include <..\arduinotester\main.c>
#include <..\arduinotester\mark_as_uncalibrated.c>
#include <..\arduinotester\message_key_released.c>
#include <..\arduinotester\part_defs.h>
#include <..\arduinotester\sampling_cap.c>
#include <..\arduinotester\sampling_lc.c>
#include <..\arduinotester\show_Resis_Cap.c>
#include <..\arduinotester\sleep_5ms.c>
#include <..\arduinotester\tt_function.h>
#include <..\arduinotester\tt_globals.h>
#include <..\arduinotester\tt_resistor.h>
#include <..\arduinotester\wait1000ms.h>
#include <..\arduinotester\wait_for_key_ms.c>
