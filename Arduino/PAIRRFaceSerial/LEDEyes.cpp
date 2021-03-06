

#include "LEDEyes.h"

// This allows the code to use the LedControl library
#include "LedControl.h"

// Pins: DIN,CLK,CS, number of Display connected
LedControl lc = LedControl(12, 11, 10, 2);

// Eye Position Arrays
byte right[] =
{
	B00111100,
	B01100110,
	B11100111,
	B11111111,
	B11111111,
	B11111111,
	B01111110,
	B00111100
};

byte left[] =
{
	B00111100,
	B01111110,
	B11111111,
	B11111111,
	B11111111,
	B11100111,
	B01100110,
	B00111100
};

byte right1[] =
{
	B00111100,
	B01111110,
	B11100111,
	B11100111,
	B11111111,
	B11111111,
	B01111110,
	B00111100
};

byte left1[] =
{
	B00111100,
	B01111110,
	B11111111,
	B11111111,
	B11100111,
	B11100111,
	B01111110,
	B00111100
};

byte center[] =
{
	B00111100,
	B01111110,
	B11111111,
	B11100111,
	B11100111,
	B11111111,
	B01111110,
	B00111100
};

byte up[] =
{
	B00111100,
	B01111110,
	B11111111,
	B11111001,
	B11111001,
	B11111111,
	B01111110,
	B00111100
};

byte up1[] =
{
	B00111100,
	B01111110,
	B11111111,
	B11110011,
	B11110011,
	B11111111,
	B01111110,
	B00111100
};

byte down[] =
{
	B00111100,
	B01111110,
	B11111111,
	B10011111,
	B10011111,
	B11111111,
	B01111110,
	B00111100
};

byte down1[] =
{
	B00111100,
	B01111110,
	B11111111,
	B11001111,
	B11001111,
	B11111111,
	B01111110,
	B00111100
};

byte blink[] =
{
	B00011000,
	B00011000,
	B00011000,
	B00011000,
	B00011000,
	B00011000,
	B00011000,
	B00011000
};

byte surprised1[] =
{
	B00111100,
	B01111110,
	B11100111,
	B11000011,
	B11000011,
	B11100111,
	B01111110,
	B00111100
};

byte surprised[] =
{
	B00111100,
	B01100110,
	B11000011,
	B10000001,
	B10000001,
	B11000011,
	B01100110,
	B00111100
};

byte happy[] =
{
	B00111100,
	B01111110,
	B11000111,
	B11000011,
	B11000011,
	B11000111,
	B01111110,
	B00111100
};

byte droopy[] =
{
  B00111000,
  B01111000,
  B11111000,
  B10011000,
  B10011000,
  B11111000,
  B01111000,
  B00111000
};

byte loading1[] =
{
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11001111,
  B11101111,
  B01111110,
  B00111100
};

byte loading2[] =
{
  B00111100,
  B01111110,
  B11101111,
  B11001111,
  B11111111,
  B11111111,
  B01111110,
  B00111100
};

byte loading3[] =
{
  B00111100,
  B01111110,
  B11110111,
  B11110011,
  B11111111,
  B11111111,
  B01111110,
  B00111100
};

byte loading4[] =
{
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11110011,
  B11110111,
  B01111110,
  B00111100
};


// Constructor, set up LED boards
LEDEyes::LEDEyes()
{
  restTime = 3000;
  delayTime = 1000;
  pauseTime = 200;
  moveTime = 50;
  SurprisedMoveTime = 120;
}
void LEDEyes::init(bool nightmode)
{
	// Wake up displays
	lc.shutdown(0, false);
  lc.shutdown(1, false);
	// Set intensity levels
  if(nightmode){
	  lc.setIntensity(0, 2);
    lc.setIntensity(1, 2);
  }else{
    lc.setIntensity(0, 5);
    lc.setIntensity(1, 5);
  }
	// Clear Displays
	lc.clearDisplay(0);
  lc.clearDisplay(1);

}

//  Take values stored in the Arrays, loop through and Display them
void LEDEyes::lookUp()
{
  for(int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		// Set the row of the given LED board(the 1st param),
  		// using the given array(3rd param)
  		lc.setRow(d, i, up[i]);
  	}
  }
}

void LEDEyes::lookUp1()
{
  for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, up1[i]);
  	}
  }
}

void LEDEyes::lookDown()
{
  for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, down[i]);
  	}
  }
}

void LEDEyes::lookDown1()
{
  for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, down1[i]);
  	}
  }
}

void LEDEyes::lookLeft()
{
  for (int d = 0; d < 2; d++)
  {	
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, left[i]);
  	}
  }
}

void LEDEyes::lookLeft1()
{
	for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, left1[i]);
  	}
  }
}

void LEDEyes::lookRight()
{
	for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, right[i]);
  	}
  }
}

void LEDEyes::lookRight1()
{
	for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, right1[i]);
  	}
  }
}

void LEDEyes::eyeCenter()
{
	for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, center[i]);
  	}
  }
}

void LEDEyes::eyeBlink()
{
  for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, blink[i]);
  	}
  }
}

void LEDEyes::surprisedEyes()
{
  for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, surprised[i]);
  	}
  }
}

void LEDEyes::surprisedEyes1()
{
  for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, surprised1[i]);
  	}
  }
}

void LEDEyes::happyEyes()
{
  for (int d = 0; d < 2; d++)
  {
  	for (int i = 0; i < 8; i++)
  	{
  		lc.setRow(d, i, happy[i]);
  	}
  }
}

void LEDEyes::droopyEyes()
{
  for (int d = 0; d < 2; d++)
  {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(d, i, droopy[i]);
    }
  }
}

/* Animation building methods */
void LEDEyes::centerLeft()
{
	eyeCenter();
	delay(delayTime);
	lookLeft1();
	delay(moveTime);
	lookLeft();
}

void LEDEyes::leftCenter()
{
	lookLeft1();
	delay(moveTime);
	eyeCenter();
}

void LEDEyes::centerRight()
{
	lookRight1();
	delay(moveTime);
	lookRight();
}

void LEDEyes::rightCenter()
{
	lookRight();
	delay(moveTime);
	lookRight1();
	delay(moveTime);
	eyeCenter();
}

void LEDEyes::centerUp()
{
	eyeCenter();
	delay(moveTime);
	lookUp1();
	delay(moveTime);
	lookUp();
}

void LEDEyes::upCenter()
{
	lookUp1();
	delay(moveTime);
	eyeCenter();
}

void LEDEyes::centerDown()
{
	eyeCenter();
	delay(moveTime);
	lookDown1();
	delay(moveTime);
	lookDown();
}

void LEDEyes::downCenter()
{
	lookDown1();
	delay(moveTime);
	eyeCenter();
}


/* Methods to create animations */
void LEDEyes::eyesAwake()
{
	eyeCenter();
	delay(delayTime);
	lookLeft1();
	delay(moveTime);
	lookLeft();
	delay(pauseTime);
	leftCenter();
	delay(moveTime);
	centerRight();
	delay(pauseTime);
	rightCenter();
	delay(moveTime);
	centerDown();
	delay(moveTime);
	downCenter();
	delay(moveTime);
	centerUp();
	delay(moveTime);
	upCenter();
	delay(pauseTime);
	eyeBlink();
	delay(pauseTime);
	eyeCenter();
}

void LEDEyes::eyesBlink()
{
	eyeCenter();
	delay(restTime);
	eyeBlink();
	delay(pauseTime);
	eyeCenter();
	delay(restTime);
	eyeBlink();
	delay(pauseTime);
	eyeCenter();
	delay(pauseTime);
	eyeBlink();
	delay(pauseTime);
	eyeCenter();
}

void LEDEyes::eyesResultRecv()
{
	surprisedEyes1();
	delay(SurprisedMoveTime);
	surprisedEyes();
	delay(SurprisedMoveTime);
	surprisedEyes1();
	delay(SurprisedMoveTime);
	eyeCenter();
	delay(SurprisedMoveTime);
	surprisedEyes1();
	delay(SurprisedMoveTime);
	surprisedEyes();
	delay(SurprisedMoveTime);
	surprisedEyes1();
	delay(SurprisedMoveTime);
	happyEyes();
	delay(3000);
	lookUp1();
	delay(moveTime);
	lookUp();
	delay(pauseTime);
	upCenter();
}

void LEDEyes::clearDisplays()
{
	lc.clearDisplay(0);
  lc.clearDisplay(1);
}

void LEDEyes::loading()
{
 for (int d = 0; d < 2; d++)
  {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(d, i, loading1[i]);
    }
  }
  delay(100);
  for (int d = 0; d < 2; d++)
  {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(d, i, loading2[i]);
    }
  }
  delay(100);
  for (int d = 0; d < 2; d++)
  {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(d, i, loading3[i]);
    }
  }
  delay(100);
  for (int d = 0; d < 2; d++)
  {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(d, i, loading4[i]);
    }
  }
  delay(100);
}


