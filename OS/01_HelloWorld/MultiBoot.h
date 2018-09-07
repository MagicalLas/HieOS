﻿#include "stdint.h"
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


#define KERNEL_STACK			0x00400000
#define FREE_MEMORY_SPACE_ADDRESS       0x00400000
#define   HEADER_ADRESS         KERNEL_LOAD_ADDRESS+ALIGN

#define MULTIBOOT_HEADER_MAGIC         0x1BADB002
#define MULTIBOOT_BOOTLOADER_MAGIC      0x2BADB002
#define MULTIBOOT_HEADER_FLAGS         0x00010003 
#define STACK_SIZE              0x4000    
#define CHECKSUM            -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)


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

//비디오 모드 정보. 그럽에서 받아옴
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


//비디오의 정보를 기록함. 상태체크인듯
struct VbeInfoBlock
{
	char Signature[4];
	unsigned short Version;
	short OEMString[2];
	unsigned char Capabilities[4];
	short VideoModes[2];
	short TotalMemory;
};

//APM테이블 관련 정보들
//Advanced Power Management (APM) table
struct APMTable
{
	unsigned short Version;
	unsigned short CS;
	unsigned int Offset;
	unsigned short CS16Bit;	//This is the 16-bit protected mode code segment
	unsigned short DS;
	unsigned short Flags;
	unsigned short CSLength;
	unsigned short CS16BitLength;
	unsigned short DSLength;
};

//롬 설정 테이블
struct ROMConfigurationTable
{
	unsigned short Length;
	unsigned char Model;
	unsigned char Submodel;
	unsigned char BiosRevision;
	bool DualBus : 1;
	bool MicroChannelBus : 1;
	bool EBDAExists : 1;
	bool WaitForExternalEventSupported : 1;
	bool Reserved0 : 1;
	bool HasRTC : 1;
	bool MultipleInterruptControllers : 1;
	bool BiosUsesDMA3 : 1;
	bool Reserved1 : 1;
	bool DataStreamingSupported : 1;
	bool NonStandardKeyboard : 1;
	bool BiosControlCpu : 1;
	bool BiosGetMemoryMap : 1;
	bool BiosGetPosData : 1;
	bool BiosKeyboard : 1;
	bool DMA32Supported : 1;
	bool ImlSCSISupported : 1;
	bool ImlLoad : 1;
	bool InformationPanelInstalled : 1;
	bool SCSISupported : 1;
	bool RomToRamSupported : 1;
	bool Reserved2 : 3;
	bool ExtendedPOST : 1;
	bool MemorySplit16MB : 1;
	unsigned char Reserved3 : 1;
	unsigned char AdvancedBIOSPresence : 3;
	bool EEPROMPresent : 1;
	bool Reserved4 : 1;
	bool FlashEPROMPresent : 1;
	bool EnhancedMouseMode : 1;
	unsigned char Reserved5 : 6;
};

//드라이브 정보
struct drive_info
{
	/* The size of this structure.  */
	unsigned long size;

	/* The BIOS drive number.  */
	unsigned char drive_number;

	/* The access mode (see below).  */
	unsigned char drive_mode;

	/* The BIOS geometry.  */
	unsigned short drive_cylinders;
	unsigned char drive_heads;
	unsigned char drive_sectors;

	/* The array of I/O ports used for the drive.  */
	unsigned short drive_ports;
};

//모듈의 정보들, 주로 포인터
struct Module
{
	void *ModuleStart;
	void *ModuleEnd;
	char *Name;
	unsigned int Reserved;
};

//Executable and Linkable Format의 테이블
// 실행 파일, 목적 파일, 공유 라이브러리 그리고 코어 덤프를 위한 표준 파일 형식이다
struct ELFHeaderTable
{
	uint32_t num;
	uint32_t size;
	uint32_t addr;
	uint32_t shndx;
};

//http://www.freenos.org/doxygen/structAoutSymbolTable.html 에 정보가 있음
//http://www.brokenthorn.com/Resources/OSDevMulti.html 관련 링크
struct AOUTSymbolTable
{
	unsigned int tabsize;
	unsigned int strsize;
	unsigned int addr;
	unsigned int reserved;
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