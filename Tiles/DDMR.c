// Exported by NeoTile

const u16 DDMRSprites[8][8] =
{
	{0x0150, 0x07f4, 0x1ffd, 0x5d7d, 0x5d7d, 0x5ffd, 0x67f6, 0x695a}, // DDMRMrRobot
	{0x0540, 0x1fd0, 0x7ff4, 0x75f5, 0x75f5, 0x7ff5, 0x9fd9, 0xa569},
	{0x6aaa, 0x6aaa, 0x6aaa, 0x6aaa, 0x6aaa, 0x6aaa, 0x6aaa, 0x1555},
	{0xaaa9, 0xaaa9, 0xaa99, 0xaa99, 0xa569, 0xaaa9, 0xaaa9, 0x5554},
	{0x0800, 0x1201, 0x8487, 0x211f, 0x087f, 0x01f7, 0x07dd, 0x1fff}, // DDMRBuzzer
	{0x0020, 0x4084, 0xd212, 0xf448, 0xfd20, 0xdf40, 0x77d0, 0xfff4},
	{0x1fff, 0x07f7, 0x01fd, 0x087f, 0x211f, 0x8487, 0x1201, 0x0800},
	{0xfff4, 0xdfd0, 0x7f40, 0xfd20, 0xf448, 0xd212, 0x4084, 0x0020}
};

enum
{
	DDMRMrRobot = DDMRSpriteBase + 0,
	DDMRBuzzer = DDMRSpriteBase + 4
};
