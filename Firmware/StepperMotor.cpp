#include "StepperMotor.h"

StepperMotor::StepperMotor(int step, int dir, int microStep1, int microStep2, int enable) : 
	stepPin(step), dirPin(dir), microStep1Pin(microStep1), microStep2Pin(microStep2), enablePin(enable)
{
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
	pinMode(microStep1Pin, OUTPUT);
	pinMode(microStep2Pin, OUTPUT);
	pinMode(enablePin, OUTPUT);
	
	enableMotor();
	setMicroSteps(fullStep);
}
void StepperMotor::write(byte dir, int numberOfSteps, int interval)
{
	if(!enableStatus) //if motor isn't enabled don't do anything
		return;
	digitalWrite(dirPin, dir); //define the direction
	int stepInterval = max(interval,stepDelay); 
	for(int i=0;i<numberOfSteps;i++) //each loop is one step
	{
		digitalWrite(stepPin,HIGH);
		delayMicroseconds (stepDelay); 	
		digitalWrite(stepPin,LOW);
		delayMicroseconds (stepInterval);
	}
}
void StepperMotor::setMicroSteps(MicroStepType type) //define micro step type
{
	switch(type)
	{
		case fullStep:
			digitalWrite(microStep1Pin,LOW);
			digitalWrite(microStep2Pin,LOW);
			stepDelay = 2000; //2mS
			break;
		case halfStep:
			digitalWrite(microStep1Pin,HIGH);
			digitalWrite(microStep2Pin,LOW);
			stepDelay = 1000; //1mS
			break;
		case quarterStep:
			digitalWrite(microStep1Pin,LOW);
			digitalWrite(microStep2Pin,HIGH);
			stepDelay = 700; //700uS
			break;
		case eigthStep:
			digitalWrite(microStep1Pin,HIGH);
			digitalWrite(microStep2Pin,HIGH);
			stepDelay = 500; //50uS
			break;
	}
} 
void StepperMotor::enableMotor() //enable
{
	digitalWrite(enablePin, LOW);
	enableStatus = 1;
}
void StepperMotor::disableMotor() //disable
{
	digitalWrite(enablePin, HIGH);
	enableStatus = 0;
}

