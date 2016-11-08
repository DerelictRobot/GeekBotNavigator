#include "GeekBot.h"

/* Robot Config Parameters */
#include "Config.h"

/* Motor Control */
#include "Motors.h"

/* Navigation and Map */
#include "Navigation.h"
#include "myMap.h"

/* I2C Line Sensor Array */
#include "LineSensorArray.h"

/* Line Following Logic and Intersection handling */
#include "LineFollower.h"

/* Sound effects */
#include <PiezoEffects.h>
PiezoEffects mySounds( BUZZER_PIN );

void GeekBot::init()
{
	pinMode(LED_LEFT_PIN, OUTPUT);
	pinMode(LED_RIGHT_PIN, OUTPUT);
	digitalWrite(LED_LEFT_PIN, HIGH);
	digitalWrite(LED_RIGHT_PIN, HIGH);
	motorsInit( LEFT_SERVO_PIN, RIGHT_SERVO_PIN );
	navigationInit( &mySounds );
	lineFollowerInit( &mySounds );
	LineSensorArrayInit();
}

bool GeekBot::lineFollow(unsigned int time)
{

	return 0;
}

void GeekBot::timedDrive(unsigned int time, int speed)	// time in mS, Speed -100 through +100
{
	motorsForward(speed);
	delay(time);
	motorsStop();
}

void GeekBot::timedRotate(unsigned int time, int speed)	// time in mS, rotation speed CCW -100 to CW +100
{
	if (speed > 0)
	{
		motorsRotateRight(speed);
		delay(time);
		motorsStop();
	}
	if (speed < 0)
	{
		motorsRotateLeft(speed);
		delay(time);
		motorsStop();
	}
	if (speed == 0)
	{
		delay(time);
		motorsStop();
	}
}

bool GeekBot::lineFind(int rotation)	//
{

	return 0;
}

void GeekBot::sound(int sound)
{
	mySounds.play( sound );
}
