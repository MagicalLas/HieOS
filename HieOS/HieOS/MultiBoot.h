#pragma once
#include "stdint.h"
#include "windef.h"

//emit해주는 매크로 생성
#define em(x)                            \
		__asm _emit	    (x)	      & 0xff \
		__asm _emit	    (x)	>> 8  & 0xff \
		__asm _emit     (x) >> 16 & 0xff \
		__asm _emit     (x) >> 24 & 0xff 

#define _Kernel_Stack 0x00400000
#define _Free_Memory_Space_Adrr 0x00400000

//설정해 놓은 것과 관련성 있음
//책 참고
#define ALIGN 0x400
#define KERNEL_LOAD_ADDRESS 0x100000
#define HEADER_ADRESS  KERNEL_LOAD_ADDRESS+ALIGN

//쓸데없어보이는 전처리과정들...
#define MULTIBOOT_HEADER_MAGIC         0x1BADB002
#define MULTIBOOT_BOOTLOADER_MAGIC      0x2BADB002
#define MULTIBOOT_HEADER_FLAGS         0x00010003 
#define STACK_SIZE              0x4000    
#define CHECKSUM            -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

//그럽용 헤더들. 여기에 쓰이는 데이터들은 엔트리 포인터에서 em로 넣어준다.
//바로 위에 정의된 것들을 사용한다.
//#pragma pack(push,1)는 이게 1바이트 단위로 저장이 된다는 것이다(구조체 크기 설정 참고)
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
//실행 파일, 목적 파일, 공유 라이브러리 그리고 코어 덤프를 위한 표준 파일 형식이래.
struct ELFHeaderTable
{
	uint32_t num;
	uint32_t size;
	uint32_t addr;
	uint32_t shndx;
};
//The symbol table for a.out이라는 설명이 있어. (노답) 그러니까 그냥 넣어둔 녀석같아.
struct AOUTSymbolTable
{
	unsigned int tabsize;
	unsigned int strsize;
	unsigned int addr;
	unsigned int reserved;
};

//비디오 모드 정보
struct VbeInfoBlock
{
	char Signature[4];
	unsigned short Version;
	short OEMString[2];
	unsigned char Capabilities[4];
	short VideoModes[2];
	short TotalMemory;
};
//비디오 모드 구조체
//설정용
struct VbeModeInfo
{
	UINT16 ModeAttributes;
	char WinAAttributes;
	char WinBAttributes;
	UINT16 WinGranularity;
	UINT16 WinSize;
	UINT16 WinASegment;
	UINT16 WinBSegment;
	UINT32 WinFuncPtr;
	short BytesPerScanLine;
	short XRes;
	short YRes;
	char XCharSize;
	char YCharSize;
	char NumberOfPlanes;
	char BitsPerPixel;
	char NumberOfBanks;
	char MemoryModel;
	char BankSize;
	char NumberOfImagePages;
	char res1;
	char RedMaskSize;
	char RedFieldPosition;
	char GreenMaskSize;
	char GreenFieldPosition;
	char BlueMaskSize;
	char BlueFieldPosition;
	char RsvedMaskSize;
	char RsvedFieldPosition;
	char DirectColorModeInfo; //MISSED IN THIS TUTORIAL!! SEE ABOVE
							  //VBE 2.0
	UINT32 PhysBasePtr;
	UINT32 OffScreenMemOffset;
	short OffScreenMemSize;
	//VBE 2.1
	short LinbytesPerScanLine;
	char BankNumberOfImagePages;
	char LinNumberOfImagePages;
	char LinRedMaskSize;
	char LinRedFieldPosition;
	char LingreenMaskSize;
	char LinGreenFieldPosition;
	char LinBlueMaskSize;
	char LinBlueFieldPosition;
	char LinRsvdMaskSize;
	char LinRsvdFieldPosition;
	char res2[194];
};

//어드벤스드 파워 메니지먼트 테이블이라는데 그냥 C++쪽 구현체에만 이런 단어가 있는듯,
//무슨 용도인지 잘 모르겠음
struct APMTable
{
	unsigned short Version;
	unsigned short CS;
	unsigned int Offset;
	unsigned short CS16Bit;
	unsigned short DS;
	unsigned short Flags;
	unsigned short CSLength;
	unsigned short CS16BitLength;
	unsigned short DSLength;
};

struct drive_info
{
	//이 구조체 크기
	unsigned long size;

	unsigned char drive_number;

	//접근모드
	unsigned char drive_mode;

	//뭔지 몰라.
	unsigned short drive_cylinders;
	unsigned char drive_heads;
	unsigned char drive_sectors;

	//IO포트
	unsigned short drive_ports;
};


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