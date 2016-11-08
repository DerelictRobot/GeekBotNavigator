#ifndef GEEKBOT_H
#define GEEKBOT_H

class GeekBot
{
	public:
		static bool lineFollow(unsigned int time);
		static void timedDrive(unsigned int time, int speed);	// time in mS, Speed -100 through +100
		static void timedRotate(unsigned int time, int speed);	// time in mS, rotation speed CCW -100 to CW +100
		static bool lineFind(int rotation);	//
		static void init();
		static void sound(int sound);
};


#endif