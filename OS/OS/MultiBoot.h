#pragma once
#include "stdint.h"
#include "windef.h"

//여기서 DD를 저장한다.
#define dd(x)                            \
        __asm _emit     (x)       & 0xff \
        __asm _emit     (x) >> 8  & 0xff \
        __asm _emit     (x) >> 16 & 0xff \
        __asm _emit     (x) >> 24 & 0xff

//여기서 이 시작지점을 표시하는 요소들을 정의한다.
#define   ALIGN               0x400
#define KERNEL_LOAD_ADDRESS            0x100000

//얘가 시작시점
#define   HEADER_ADRESS         KERNEL_LOAD_ADDRESS+ALIGN

//특정 시그니쳐를 나타낸다. 그럽용
#define MULTIBOOT_HEADER_MAGIC         0x1BADB002
#define MULTIBOOT_BOOTLOADER_MAGIC      0x2BADB002

//여기서 부팅하는데 필요한 정보의 구조체를 만든다.
#pragma pack(push,1)
struct MULTIBOOT_HEADER {
	uint32_t magic;
	uint32_t flags;
	uint32_t checksum;
	uint32_t header_addr;
	uint32_t load_addr;
	uint32_t load_end_addr;
	uint32_t bss_end_addr;
	uint32_t entry_addr;
};


//그럽이 주는 정보들을 담는 구조체. 위에 있는 것들의 끝판왕임
struct multiboot_info
{
	/* Multiboot info version number */
	uint32_t flags;

	/* Available memory from BIOS */
	uint32_t mem_lower;
	uint32_t mem_upper;

	/* "root" partition */
	uint32_t boot_device;

	/* Kernel command line */
	char *cmdline;

	/* Boot-Module list */
	uint32_t mods_count;
	Module *Modules;

	union
	{
		AOUTSymbolTable AOUTTable;
		ELFHeaderTable ELFTable;
	} SymbolTables;

	/* Memory Mapping buffer */
	uint32_t mmap_length;
	uint32_t mmap_addr;

	/* Drive Info buffer */
	uint32_t drives_length;
	drive_info * drives_addr;

	/* ROM configuration table */
	ROMConfigurationTable *ConfigTable;

	/* Boot Loader Name */
	char* boot_loader_name;

	/* APM table */
	APMTable *APMTable;

	/* Video */
	VbeInfoBlock *vbe_control_info;
	VbeModeInfo *vbe_mode_info;
	uint16_t vbe_mode;
	uint16_t vbe_interface_seg;
	uint16_t vbe_interface_off;
	uint16_t vbe_interface_len;
};
typedef struct multiboot_info multiboot_info_t;
