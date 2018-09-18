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
void LasConsole::init() {
	
	_xPos = 0;
	_yPos = 0;

	_ScreenHeight = 30;
	_ScreenWidth = 80;

	_backGroundColor = ConsoleColor::White;
	_Text = ConsoleColor::Black;
	_Color = ConsoleColor::Cyan;
}