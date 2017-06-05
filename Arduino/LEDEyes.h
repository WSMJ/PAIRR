#ifndef _LEDEYES_h
#define _LEDEYES_h

#include "arduino.h"

class LEDEyes
{

public:
	// Constructor
	LEDEyes();

	// These methods layout a single frame
	// Kept public so custom faces can still be made using this library
	void lookLeft();
	void lookLeft1();
	void lookRight();
	void lookRight1();
	void lookUp();
	void lookUp1();
	void lookDown();
	void lookDown1();
	void eyeCenter();
	void eyeBlink();
	void surprisedEyes();
	void surprisedEyes1();
	void happyEyes();

	// Simple animations to construct larger ones
	void centerLeft();
	void leftCenter();
	void centerRight();
	void rightCenter();
	void centerUp();
	void upCenter();
	void centerDown();
	void downCenter();

	// Animate eyes
	void eyesAwake();
	void eyesResultRecv();
	void eyesBlink();
	void clearDisplays();


private:
	unsigned long delayTime;
	unsigned long pauseTime;
	unsigned long moveTime;
	unsigned long restTime;
	unsigned long SurprisedMoveTime;
};
#endif