#include "Piezo.h"

Piezo::Piezo(int pin) : signalPin(pin) {}
int Piezo::read() //return Piezo reading
{
	return analogRead(signalPin);
}

