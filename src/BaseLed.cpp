/*
 * SuperLed.cpp
 * BaseLed
 *
 *  Created on: 6 jul. 2016
 *      Author: valdez
 */

#include "BaseLed.h"
#include "Arduino.h"


BaseLed::BaseLed(uint8_t pin, unsigned long ton, unsigned long toff) :
	_pin(pin), _ton(ton), _toff(toff) {

	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	_state = LOW;
	_millis = millis();
	_enabled = false;
}


void BaseLed::setPeriod(unsigned long ton, unsigned long toff) {
	_ton = ton;
	_toff = toff;
}


bool BaseLed::getState() {
	return _state;
}


void BaseLed::start() {
	_enabled = true;
}


void BaseLed::stop() {
	_enabled = false;
	_state = LOW;
	digitalWrite(_pin, _state);
}


void BaseLed::update() {
	if (!_enabled) return;

	if ((_state == HIGH) && (millis() - _millis > _ton)) {
		_millis = millis();
		_state = LOW;
		digitalWrite(_pin, _state);
	} else if ((_state == LOW) && (millis() - _millis > _toff)) {
		_millis = millis();
		_state = HIGH;
		digitalWrite(_pin, _state);
	};
}




