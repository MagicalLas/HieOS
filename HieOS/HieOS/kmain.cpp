#include "kmain.h"

_declspec(naked) void multiboot_entry(void)
{
	__asm {
		align 4

		multiboot_header:

		kernel_entry:
	}
}