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

	for (;;);

}