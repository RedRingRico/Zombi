#ifndef __ZOMBI_DATATYPES_HPP__
#define __ZOMBI_DATATYPES_HPP__

#include <stdint.h>

typedef signed char		ZOM_SCHAR8;
typedef unsigned char	ZOM_UCHAR8;
typedef ZOM_UCHAR8		ZOM_BYTE;
typedef int16_t			ZOM_SINT16;
typedef uint16_t		ZOM_UINT16;
typedef int32_t			ZOM_SINT32;
typedef uint32_t		ZOM_UINT32;
typedef int64_t			ZOM_SINT64;
typedef uint64_t		ZOM_UINT64;
typedef float			ZOM_FLOAT32;
typedef double			ZOM_FLOAT64;

const ZOM_UINT32 ZOM_OK		= 0x00000000;
const ZOM_UINT32 ZOM_FAIL	= 0xFFFFFFFF;

#endif // __ZOMBI_DATATYPES_HPP__

