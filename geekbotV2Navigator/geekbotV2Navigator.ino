/***********************************************************************************
 *                         RobotGeek Geekbot V2 Line Navigator
 *  __________________
 *   |              |
 *   |     ___      |
 *  _|____/___\ ____|_
 *   \_/  \___/   \_/
 *
 *  Wiring
 *
 *    Rotation Knob - Analog Pin 0
 *    Left Servo - Digital Pin 10
 *    Right Servo - Digital Pin 11
 *    Buzzer - Digital Pin 12
 *    IR Receiver - Digital Pin 2
 *    Right LED - Digital Pin 4
 *    Left LED - Digital Pin 7
 *    Line Sensor Array - I2C
 *    LCD (4 line) - I2C
 *    LCD Up Button - Digital Pin 3
 *    LCD Down Button - Digital Pin 9
 *    LCD Play Button - Digital Pin 1
 *    LCD Stop Button - Digital Pin 8
 *
 *    Jumper for pins 9/10/11 should be set to 'VIN'
 *    Jumper for pins 3/5/6 should be set to '5V'
 *
 *  Control Behavior:
 *
 *    Put it on a line and use the LCD panel to navigate between destinations.
 *    Use the Rotation Knob to adjust forward driving trim.
 *    Customize your nagivation routes in myMap.cpp
 *
 *  External Resources
 *
 ***********************************************************************************/

#include <PiezoEffects.h>

/* GeekBot API */
#include "GeekBot.h"
/* Robot Config Parameters */
#include "Config.h"


// Create GeekBot object, named myGeekBot
GeekBot myGeekBot;

void setup()
{
  Serial.begin(38400);
  Serial.println("Geekbot Navigator Starting...");

  myGeekBot.init();
  delay(1000);
  myGeekBot.sound(soundUp);

}

void loop()
{
  // myGeekBot.timedRotate(10, 10); // time in mS, rotation speed CCW -100 to CW +100
  // myGeekBot.sound(soundDown);
  // delay(3000);
  // myGeekBot.lineFollow(0); // 0 = follow until intersection, 1-10,000 = time in mS to follow line
  // delay(1000);
  myGeekBot.timedDrive(5000, 0); // time in mS, Speed -100 through +100
  myGeekBot.sound(soundUp);
  delay(1000);
  myGeekBot.timedDrive(5000, 50); // time in mS, Speed -100 through +100
  myGeekBot.sound(soundDown);
  delay(1000);
  myGeekBot.timedDrive(5000, 100); // time in mS, Speed -100 through +100
  myGeekBot.sound(soundUp);
  delay(1000);
  myGeekBot.timedRotate(2000, 50);
}
