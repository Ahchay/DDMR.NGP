#include "ngpc.h"
#include "library.h"
#include "mrrobot.h"
#include "Tiles/DDMRSprites.c"

void DontDieMrRobot(void)
{
	u8 iLoop;
	u8 iFrame;
	u8 iBlank;
	SPRITE SpriteList[16];

	// Just create a sprite for now...
	ClearScreen(SCR_1_PLANE);
	ClearScreen(SCR_2_PLANE);
	ClearSprites();

	SpriteList[0].xPosition=64;
	SpriteList[0].yPosition=64;
	SpriteList[0].SpriteID=0;
	SpriteList[0].SpriteType=0;
	SpriteList[0].BaseTile=DDMRSpriteBase;
	SpriteList[0].Frame=0;
	SpriteList[0].Direction=0;

	for (iLoop=1;iLoop<=15;iLoop++)
	{
		SpriteList[iLoop].xPosition=(((u16)QRandom())<<8);
		SpriteList[iLoop].yPosition=(((u16)QRandom())<<8);
		SpriteList[iLoop].SpriteID=iLoop<<2;
		SpriteList[iLoop].SpriteType=1;
		SpriteList[iLoop].BaseTile=DDMRSpriteBase+(iLoop<<2);
		SpriteList[iLoop].Frame=0;
		SpriteList[iLoop].Direction=iLoop;
	}

	CreateDDMRSprites();

	iFrame=0;
	iBlank=VBCounter;

	while(1)
	{
		// A basic frame counter...
		iFrame++;
		if(iBlank!=VBCounter)
		{
			PrintDecimal(SCR_1_PLANE,0,0,0,iFrame,8);
			iFrame=0;
			iBlank=VBCounter;
		}

		for (iLoop=0;iLoop<=15;iLoop++)
		{
			CopyAnimationFrame(DDMRSprites, SpriteList[iLoop].BaseTile, SpriteList[iLoop].SpriteType, 4, SpriteList[iLoop].Frame);
			SetSpritePosition(SpriteList[iLoop].SpriteID, (u8)(SpriteList[iLoop].xPosition>>8), (u8)(SpriteList[iLoop].yPosition>>8));
			if (SpriteList[iLoop].Direction & 1)
				SpriteList[iLoop].xPosition+=32;
			if (SpriteList[iLoop].Direction & 2)
				SpriteList[iLoop].yPosition+=32;
			if (SpriteList[iLoop].Direction & 4)
				SpriteList[iLoop].xPosition-=32;
			if (SpriteList[iLoop].Direction & 8)
				SpriteList[iLoop].yPosition-=32;
		}

		if (JOYPAD & J_DOWN)
			SpriteList[0].yPosition+=64;
		if (JOYPAD & J_UP)
			SpriteList[0].yPosition-=64;
		if (JOYPAD & J_RIGHT)
			SpriteList[0].xPosition+=64;
		if (JOYPAD & J_LEFT)
			SpriteList[0].xPosition-=64;

	}
}

void CreateDDMRSprites(void)
{
	u8 iLoop;
	u8 iPalette;
	//Rather than copy a blind set of tiles in, we'll leave the tile ram alone
	//and the main loop will copy each individual sprite animation into memory as it needs it
	//InstallTileSetAt(DDMRSprites, sizeof(DDMRSprites)/2, DDMRMrRobot);

	SetPalette(SPRITE_PLANE, PAL_MRROBOT, RGB(0,0,0), RGB(0,0,0), RGB(0,15,15), RGB(15,15,15));
	SetPalette(SPRITE_PLANE, PAL_BUZZER, RGB(0,0,0), RGB(0,0,0), RGB(15,0,0), RGB(3,15,3));

	iPalette=PAL_MRROBOT;

	for (iLoop=0;iLoop<64;iLoop+=4)
	{
		SetSprite(iLoop, DDMRSpriteBase + iLoop, 0, 0, 0, iPalette);
		SetSprite(iLoop+1, DDMRSpriteBase + iLoop+ 1, 1, 8, 0, iPalette);
		SetSprite(iLoop+2, DDMRSpriteBase + iLoop+ 2, 1, -8, 8, iPalette);
		SetSprite(iLoop+3, DDMRSpriteBase + iLoop+ 3, 1, 8, 0, iPalette);

		iPalette=PAL_BUZZER;
	}
}
