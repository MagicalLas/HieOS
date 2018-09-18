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
	unsigned int video_memory;
	ushort* m_pVideoMemory = (unsigned short*)0xb0000;

	char video_type = (*(unsigned short*)0x410 & 0x30);

	if (video_type == 0x30) {
		video_memory = VGA_MONO_CRT_ADDRESS;
	}
	else {
		video_memory = VGA_COLOR_CRT_ADDRESS;
	}

	unsigned int m_ScreenHeight = 25;
	unsigned int m_ScreenWidth = 80;

	uint m_xPos = 0;
	uint m_yPos = 0;

	ConsoleColor m_Text = White;
	ConsoleColor m_backGroundColor = Black;
	ConsoleColor m_Color = (ConsoleColor)((m_backGroundColor << 4) | m_Text);
}