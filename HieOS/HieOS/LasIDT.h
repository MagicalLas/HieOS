#pragma once

#include "stdint.h"

struct IDTR
{
	uint16_t limit;
	uint32_t base;
};

