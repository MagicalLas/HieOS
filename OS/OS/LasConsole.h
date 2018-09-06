#ifndef LASCONSOLE_H
#define LASCONSOLE_H
#include "windef.h"

//콘솔의 색 지정
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
/*
http://www.osdever.net/FreeVGA/vga/vgareg.htm 여기보면 나와있을 것 같은데 모르겠다
ioctl하기 위한 주소같다. 
리눅스에서는 ioperm(set port input/output permissions)으로 
ioperm(0x3b4, 0x3df - 0x3b4 + 1, 1)
처럼 비디오를 켜거나 끈다. 그냥 정해져 있는 포트인듯
*/
#define VGA_COLOR_CRT_ADDRESS 0x3D4
#define VGA_MONO_CRT_ADDRESS 0x3B4

#endif
