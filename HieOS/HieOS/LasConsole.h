#ifndef LasConsole_h
#define LasConsole_h
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

//그래픽카드 관련 몇가지 설정들
//숫자가 낮으니 더해서 사용 할 듯
#define VGA_CRT_CURSOR_START 0x0A
#define VGA_CRT_CURSOR_END 0x0B
#define VGA_CRT_H_START_ADDRESS 0x0C
#define VGA_CRT_H_END_ADDRESS 0x0D
#define VGA_CRT_CURSOR_H_LOCATION 0x0E
#define VGA_CRT_CURSOR_L_LOCATION 0x0F



namespace LasConsole {

	void init();
	void move_cursor(unsigned int  X, unsigned int  Y);
	void print(char c);
	void Clear();
}
#endif