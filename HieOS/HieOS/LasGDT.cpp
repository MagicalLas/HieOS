#include"LasGDT.h"
//테이블 정의
//10개의 GDT 설정
static GDT_descripter gdt[10];

static GDTR gdtr;

//! Setup a descriptor in the Global Descriptor Table
void gdt_set_descriptor(uint32_t i, uint64_t base, uint64_t limit, uint8_t access, uint8_t grand)
{
	if (i > 10)
		return;

	//! null out the descriptor
	memset((void*)&gdt[i], 0, sizeof(GDT_descripter));

	//! set limit and base addresses
	gdt[i].base_low = uint16_t(base & 0xffff);
	gdt[i].base_middle = uint8_t((base >> 16) & 0xff);
	gdt[i].base_high = uint8_t((base >> 24) & 0xff);
	gdt[i].segment_limit = uint16_t(limit & 0xffff);

	//! set flags and grandularity bytes
	gdt[i].flag = access;
	gdt[i].grand = uint8_t((limit >> 16) & 0x0f);
	gdt[i].grand |= grand & 0xf0;
}

void gdt_init() {
	gdtr.limit = (sizeof(struct GDT_descripter) * 10) - 1;
	gdtr.base = (uint32_t)&gdt[0];

	//NULL 디스크립터의 설정
	gdt_set_descriptor(0, 0, 0, 0, 0);

	//커널 코드 디스크립터의 설정
	gdt_set_descriptor(1, 0, 0xffffffff,
		I86_GDT_DESC_READWRITE | I86_GDT_DESC_EXEC_CODE | I86_GDT_DESC_CODEDATA |
		I86_GDT_DESC_MEMORY, I86_GDT_GRAND_4K | I86_GDT_GRAND_32BIT |
		I86_GDT_GRAND_LIMITHI_MASK);

	//커널 데이터 디스크립터의 설정
	gdt_set_descriptor(2, 0, 0xffffffff,
		I86_GDT_DESC_READWRITE | I86_GDT_DESC_CODEDATA | I86_GDT_DESC_MEMORY,
		I86_GDT_GRAND_4K | I86_GDT_GRAND_32BIT | I86_GDT_GRAND_LIMITHI_MASK);

	//유저모드 디스크립터의 설정
	gdt_set_descriptor(3, 0, 0xffffffff,
		I86_GDT_DESC_READWRITE | I86_GDT_DESC_EXEC_CODE | I86_GDT_DESC_CODEDATA |
		I86_GDT_DESC_MEMORY | I86_GDT_DESC_DPL, I86_GDT_GRAND_4K | I86_GDT_GRAND_32BIT |
		I86_GDT_GRAND_LIMITHI_MASK);

	//유저모드 데이터 디스크립터의 설정
	gdt_set_descriptor(4, 0, 0xffffffff, I86_GDT_DESC_READWRITE | I86_GDT_DESC_CODEDATA | I86_GDT_DESC_MEMORY | I86_GDT_DESC_DPL,
		I86_GDT_GRAND_4K | I86_GDT_GRAND_32BIT | I86_GDT_GRAND_LIMITHI_MASK);
	_asm lgdt[gdtr]
}