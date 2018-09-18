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

//레지스터에 넣을 구조체
struct GDTR
{
	USHORT limit;
	UINT base;
};

//테이블 정의
//10개의 GDT가 들어감
static GDT_descripter _gdt[10];