/*
 * SuperLed.h
 *
 *  Created on: 6 jul. 2016
 *      Author: valdez
 */

#ifndef SUPERLED_H_
#define SUPERLED_H_

#include "BaseLed.h"
#include "Arduino.h"

/**
 * El SuperLed permite configurar Ton, Toff, initial Delay y número total de ciclos a realizar.
 * Para ciclos indefinidos, no llamar al método setCycles o llamarlo con parámetro nCycles=0.
 * Importante:  el Timer debe iniciarse DESPUES de iniciar el SuperLed.
 * update() debe llamarse cada 1T, donde T es la unidad de tiempo deseada para Ton, Toff y Delay.
 */

class SuperLed: public BaseLed {
private:
	unsigned long _iniDelay, _delayCnt;
	unsigned long _nCycles, _cyCount, _msCount;
	unsigned long _tmpTon = 0, _tmpToff = 0, _tmpNCycles = 0;
	bool _tempSettings;

public:
	SuperLed(unsigned char pin, unsigned long ton, unsigned long toff,
			unsigned long iniDelay = 0) :
			BaseLed(pin, ton, toff), _iniDelay(iniDelay), _delayCnt(iniDelay), _nCycles(
					0), _cyCount(0), _msCount(0), _tempSettings(false) {
	}
	;

	void setCycles(unsigned long nCycles) {
		_nCycles = nCycles;
	}
	;

	void config(unsigned long ton, unsigned long toff, unsigned long nCycles);
	void set(bool state);
	void toggle();
	void start();
	void start(unsigned long ton, unsigned long toff, unsigned long nCycles);
	void update();
};

#endif /* SUPERLED_H_ */
