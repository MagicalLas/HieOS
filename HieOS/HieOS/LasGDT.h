#include <stdint.h>

#include "string.h"
#include "memory.h"
#include "windef.h"
#include "defines.h"

//GDT구조체 정의
struct GDT_descripter
{
	uint16_t segment_limit;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t flag;
	uint8_t grand;
	uint8_t base_high;
};

//레지스터에 넣을 구조체
struct GDTR
{
	uint16_t limit;
	uint8_t base;
};

//테이블 정의
//10개의 GDT가 들어감
static GDT_descripter _gdt[10];