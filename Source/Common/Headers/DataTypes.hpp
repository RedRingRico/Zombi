#ifndef __ZOMBI_DATATYPES_HPP__
#define __ZOMBI_DATATYPES_HPP__

#include <stdint.h>
#if defined ZOMBI_PLATFORM_LINUX_X86_64
#include <DataTypes_Linux_x86_64.hpp>
#elif defined ZOMBI_PLATFORM_LINUX_X86_32
#include <DataTypes_Linux_x86_32.hpp>
#else
#error Unknown platform
#endif

typedef signed char		ZOM_SCHAR8;
typedef unsigned char	ZOM_UCHAR8;
typedef ZOM_UCHAR8		ZOM_BYTE;
typedef int16_t			ZOM_SINT16;
typedef uint16_t		ZOM_UINT16;
typedef int32_t			ZOM_SINT32;
typedef uint32_t		ZOM_UINT32;
typedef int64_t			ZOM_SINT64;
typedef uint64_t		ZOM_UINT64;
typedef size_t			ZOM_MEMSIZE;
typedef float			ZOM_FLOAT32;
typedef double			ZOM_FLOAT64;

typedef ZOM_UINT32	ZOM_BOOL;

const ZOM_UINT32 ZOM_OK		= 0x00000000;
const ZOM_UINT32 ZOM_FAIL	= 0xFFFFFFFF;

const ZOM_BOOL ZOM_TRUE = 1;
const ZOM_BOOL ZOM_FALSE = 0;

#define ZOM_NULL nullptr

#endif // __ZOMBI_DATATYPES_HPP__

