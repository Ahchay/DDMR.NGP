#include "ngpc.h"
#include "carthdr.h" // TODO: edit game name in carthdr.h
#include "library.h"
#include "mrrobot.h"



void main()
{
	InitNGPC();
	SysSetSystemFont();

	ClearScreen(SCR_1_PLANE);
	ClearScreen(SCR_2_PLANE);
	SetBackgroundColour(RGB(0, 0, 0));

	while(1) // never fall out of main!!!
	{
		//Display logo/game select screen

		//Wait for player and then...
		DontDieMrRobot();
	}
}


