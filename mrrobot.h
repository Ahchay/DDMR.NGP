#define MRROBOT

#define PAL_MRROBOT 0
#define PAL_BUZZER 1

#define DDMRSpriteBase 256

enum // sprite key
{
	DDMR_MrRobot = 0,
	DDMR_Buzzer = 1
};

typedef struct Sprite
{
	u16 xPosition;
	u16 yPosition;
	u8 SpriteID;
	u16 SpriteType;
	u16 BaseTile;
	u16 Frame;
	u16 Direction;
} SPRITE;

void DontDieMrRobot(void);
void CreateDDMRSprites(void);