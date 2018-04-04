#include "ngpc.h"
#include "carthdr.h" // TODO: edit game name in carthdr.h
#include "library.h"
#include "mrrobot.h"



void main()
{
	InitNGPC();
	SysSetSystemFont();

	// TODO: add game code - and remove hello world :-)

	ClearScreen(SCR_1_PLANE);
	ClearScreen(SCR_2_PLANE);
	SetBackgroundColour(RGB(0, 0, 0));

	SetPalette(SCR_1_PLANE, 0, 0, 0, 0, RGB(15,15,15));
	PrintString(SCR_1_PLANE, 0, 4, 9, "HELLO WORLD!");

	DontDieMrRobot();

	while(1); // never fall out of main!!!
}


