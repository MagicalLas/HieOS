#include"LasConsole.h"
namespace LasConsole {
	static ConsoleColor _Color;
	static ConsoleColor _Text;
	static ConsoleColor _backGroundColor;

	static uint _xPos;
	static uint _yPos;

	static ushort* _pVideoMemory; //Just a pointer to video memory
	static unsigned int _ScreenHeight;
	static unsigned int _ScreenWidth;
	static unsigned short _VideoCardType;
}