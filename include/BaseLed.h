/*
 * BaseLed.h
 *
 *  Created on: 6 jul. 2016
 *      Author: valdezM
 */

#ifndef BASELED_H_
#define BASELED_H_

#include "Arduino.h"


class BaseLed {
protected:
	unsigned char _pin;
	long unsigned int _millis, _ton, _toff;

	bool _state, _enabled;


public:
	BaseLed(unsigned char pin, unsigned long ton, unsigned long toff);
	void setPeriod(unsigned long ton, unsigned long toff);
	virtual void start();
	void stop();
	virtual void update();
	bool getState();
	virtual ~BaseLed() {};
};


#endif /* BASELED_H_ */
