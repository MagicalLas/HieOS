#include <stdint.h>

#include "string.h"
#include "memory.h"
#include "windef.h"
#include "defines.h"

//GDT구조체 정의
struct GDT_descripter
{
	USHORT segment_limit;
	USHORT base_low;
	BYTE base_middle;
	BYTE flag;
	BYTE grand;
	BYTE base_high;
};

