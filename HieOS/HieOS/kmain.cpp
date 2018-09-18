#include "kmain.h"

_declspec(naked) void multiboot_entry(void)
{
	__asm {
		align 4

		multiboot_header:
		em(MULTIBOOT_HEADER_MAGIC); magic munber
		em(MULTIBOOT_HEADER_FLAGS); flags
		em(CHECKSUM); checksum
		em(HEADER_ADRESS);
		em(KERNEL_LOAD_ADDRESS);
		em(00);
		em(00);
		em(HEADER_ADRESS + 0x20);

		kernel_entry:
		mov esp, _Kernel_Stack;

		push 0;
		popf

		push ebx;
		push eax;

		call kmain;

		h:
		jmp h;
	}
}

void kmain(unsigned long magic, unsigned long addr)
{
	LasConsole::init();
	LasConsole::Clear();
	LasConsole::move_cursor(1, 2);
	LasConsole::print('W');
	LasConsole::move_cursor(2, 2);
	LasConsole::print('o');
	LasConsole::move_cursor(3, 2);
	LasConsole::print('n');
	LasConsole::move_cursor(4, 2);
	LasConsole::print('H');
	LasConsole::move_cursor(5, 2);
	LasConsole::print('o');
	LasConsole::move_cursor(6, 2);
	LasConsole::print('-');
	LasConsole::move_cursor(7, 2);
	LasConsole::print('L');
	LasConsole::move_cursor(8, 2);
	LasConsole::print('A');
	LasConsole::move_cursor(9, 2);
	LasConsole::print('S');


	LasConsole::move_cursor(1, 3);
	LasConsole::print('H');
	LasConsole::move_cursor(2, 3);
	LasConsole::print('i');
	LasConsole::move_cursor(3, 3);
	LasConsole::print('e');
	LasConsole::move_cursor(4, 3);
	LasConsole::print('O');
	LasConsole::move_cursor(5, 3);
	LasConsole::print('S');
	LasConsole::move_cursor(6, 4);
	LasConsole::print('M');
	LasConsole::move_cursor(7, 4);
	LasConsole::print('A');
	LasConsole::move_cursor(8, 4);
	LasConsole::print('D');
	LasConsole::move_cursor(9, 4);
	LasConsole::print('E');
	for (;;);

}