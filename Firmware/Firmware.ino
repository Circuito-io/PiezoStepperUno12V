#include "Global.h"

void setup() 
{
	Serial.begin(9600);
	Serial.println("start");
	
	motor.setMicroSteps(fullStep);
	
}

void loop() 
{	
	int sample = piezo.read();
	if(sample > 10) //if sample above thershold
	{
		motor.write(1, 100, 2500);
		delay(500);
		motor.write(0, 100, 2500);
		delay(500);
	}

		
	delay(5);
  
}
