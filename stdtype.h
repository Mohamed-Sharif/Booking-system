#ifndef Stdtype
#define Stdtype
// This is to give descriptive names for general signed and unsigned data types
// the new name consists of the number of bits and whether it is signed or unsigned
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned long int u32;
// for example: (int) is a signed dtype with 32 bits so it becomes s32
typedef signed long int s32;
// every time I write s32 I mean int
typedef float f32;
typedef double f64;
typedef long double f96;
#endif
