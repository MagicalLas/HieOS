#include "kmain.h"

_declspec(naked) void multiboot_entry(void)
{
	__asm {
		align 4

		multiboot_header:
		em(MULTIBOOT_HEADER_MAGIC);
		em(MULTIBOOT_HEADER_FLAGS);
		em(CHECKSUM);
		em(HEADER_ADRESS);
		em(KERNEL_LOAD_ADDRESS);
		kernel_entry:
	}
}