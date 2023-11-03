#include "Arduino.h"
#include "TimerOne.h"
#include "SuperLed.h"

SuperLed *sLed;

void setup() {
	Serial.begin(9600);
	Serial.write("\n\nSuperLedDemo\n\n");

	Timer1.stop();  // Importante DETENER el timer al iniciar
	Timer1.initialize(1000);
	Timer1.attachInterrupt(T1_isr);

	/**
	 *  Configurar pin 38 como SuperLed, con:
	 *	- Ton = 200ms, Toff = 300ms
	 *	- Tdelay = 1000ms
	 *	- Cantidad de ciclos a realizar = 10
	 *	- IMPORTANTE: Iniciar el Timer1 despues de iniciar el SuperLed.
	 */

	sLed = new SuperLed(38, 200, 300, 1000);
	sLed->setCycles(10);
	sLed->start();

	Timer1.start();

}

void loop() {

}

void T1_isr() {
	sLed->update();
}
