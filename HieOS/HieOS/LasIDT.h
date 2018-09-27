#pragma once

#include "stdint.h"

typedef void(_cdecl *I86_IRQ_HANDLER)(void);

struct IDTR
{
	uint16_t limit;
	uint32_t base;
};

struct IDT_descripter
{
	uint16_t offset_low;
	uint16_t selector;
	uint8_t reserved;
	uint8_t flag;
	uint16_t offset_high;
};