/*

  ButtonMouseControl
  For Leonardo and Due boards only.
  Controls the mouse from five pushbuttons on an Arduino Leonardo, Micro or Due.

  Hardware:
  - five pushbuttons attached to D2, D3, D4, D5, D6
  The mouse movement is always relative. This sketch reads four pushbuttons,
  and uses them to set the movement of the mouse.
  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 15 Mar 2012
  modified 27 Mar 2012
  by Tom Igoe

  This example code is in the public domain.
  https://www.arduino.cc/en/Tutorial/ButtonMouseControl

*/

#include "Mouse.h"

// set pin numbers for the buttons:
const int mouseButton = 10;

int range = 5;              // output range of X or Y movement; affects movement speed
int responseDelay = 100;     // response delay of the mouse, in ms

void setup() 
{
	pinMode(mouseButton, INPUT);
  	//initialize mouse control:
  	Mouse.begin();
}

void loop() 
{
	int clickState = digitalRead(mouseButton);
	// if the mouse button is pressed:

	if (clickState == HIGH) 
	{
		// if the mouse is not pressed, press it:
		if (!Mouse.isPressed(MOUSE_LEFT)) 
		{
      			Mouse.press(MOUSE_LEFT);
            delay(responseDelay);
            Mouse.release(MOUSE_LEFT);
    }
  }
}