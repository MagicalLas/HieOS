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

