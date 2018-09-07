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

