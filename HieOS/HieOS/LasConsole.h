#ifndef LasConsole
#define LasConsole
#include "windef.h"

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	LightBrown = 14,
	White = 15
};

//그래픽 카드 주소 정의
//여기에 값 넣으면 출력됨
//흑백은 좀 다름
#define VGA_COLOR_CRT_ADDRESS 0x3D4
#define VGA_MONO_CRT_ADDRESS 0x3B4

#endif