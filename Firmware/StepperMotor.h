#ifndef StepperMotor_H
#define StepperMotor_H

#include "arduino.h"

//micro steps types
enum MicroStepType { fullStep, halfStep, quarterStep, eigthStep };

class StepperMotor
{
	public:
		StepperMotor(int step, int dir, int microStep1, int microStep2, int enable);
		void write(byte dir, int numberOfSteps, int interval);
		void setMicroSteps(MicroStepType type);
		void enableMotor();
		void disableMotor();
		
	private:
		const int stepPin,dirPin,microStep1Pin,microStep2Pin,enablePin;
		byte enableStatus = 0;
		int stepDelay = 2000;//delay while step pin is toggle, change when setMicroStep called. in uS
};
#endif //StepperMotor_H
