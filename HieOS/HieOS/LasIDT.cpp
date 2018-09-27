#include "LasIDT.h"

static IDT_descripter	idt[256];

IDT_descripter * get_interrupt_descripter(uint16_t index) {
	return &idt[index];
}
