/*
 * SuperLed.cpp
 *
 *  Created on: 6 jul. 2016
 *      Author: valdez
 */

#include "SuperLed.h"
#include "Arduino.h"

void SuperLed::set(bool state) {
	_enabled = false;
	_state = state;
	digitalWrite(_pin, _state);
}

void SuperLed::toggle() {
	_enabled = false;
	_state = !_state;
	digitalWrite(_pin, _state);
}

void SuperLed::update() {
	if (!_enabled)
		return;

	if (_delayCnt) {
		--_delayCnt;
		return;
	}

	if ((_nCycles > 0) && (_cyCount > _nCycles)) {
		if (_tempSettings) {
			_ton = _tmpTon;
			_toff = _tmpToff;
			_nCycles = _tmpNCycles;
			_tempSettings = false;
		}
		return;
	}

	switch (_state) {
	case HIGH:
		if (--_msCount == 0) {
			_msCount = _toff;
			_state = LOW;
			digitalWrite(_pin, _state);
			++_cyCount; // ciclo completado
		}
		break;

	case LOW:
		if (--_msCount == 0) {
			_msCount = _ton;
			_state = HIGH;
			digitalWrite(_pin, _state);
		}
		break;
	}
}

void SuperLed::start() {
	//BaseLed::start();
	_enabled = true;
	_msCount = _ton;
	_delayCnt = _iniDelay;
	_cyCount = 0;
	_state = HIGH;
}

void SuperLed::config(unsigned long ton, unsigned long toff, unsigned long nCycles) {
	_ton = ton;
	_toff = toff;
	setCycles(nCycles);
}

void SuperLed::start(unsigned long ton, unsigned long toff,
		unsigned long nCycles) {
	_tmpTon = _ton;
	_tmpToff = _toff;
	_tmpNCycles = _nCycles;
	_tempSettings = true;
	config(ton, toff, nCycles);
	start();
}

