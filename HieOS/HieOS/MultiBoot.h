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