#include <stdio.h>
#include "stdint.h"

#define SET_BIT(x, pos) (x |= (1U << pos))
#define CLEAR_BIT(x, pos) (x &= (~(1U << pos)))
#define TOGGLE_BIT(x, pos) (x ^= (1U << pos))
#define CHECK_BIT(x, pos) ((x >> pos) & 1ULL)
#define SET_BITMASK(x, mask) ((x) |= (mask))
#define CLEAR_BITMASK(x, mask) ((x) &= (~(mask)))
#define SWAP_UINT16(x) (((x) << 8) & 0xff00 | ((x) >> 8)) //bswap16
#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

#undef MIN
#undef MAX
#define MIN(a, b)   (((a) < (b)) ? (a) : (b))
#define MAX(a, b)   (((a) > (b)) ? (a) : (b))

void test_defines(void)
{
	printf("sizeof(uint8_t): %0lx\n", sizeof(uint8_t));    // 1
	printf("sizeof(uint16_t): %0lx\n", sizeof(uint16_t));  // 2
	printf("sizeof(uint32_t) %0lx\n", sizeof(uint32_t));   // 4
	printf("sizeof(uint64_t) %0lx\n", sizeof(uint64_t));   // 8
	printf("------------------\n");
	printf("sizeof(char): %d\n", (int)sizeof(char));       // 1 (8 bit)
	printf("sizeof(short): %d\n", (int)sizeof(short));     // 2 (16 bit)
	printf("sizeof(int): %d\n", (int)sizeof(int));         // 4 (32 bit)
	printf("sizeof(float): %f\n", (float)sizeof(float));   // 4 (32 bit float)
	printf("sizeof(long): %ld\n", (long)sizeof(long));     // 8 (64 bit)
	printf("sizeof(double): %f\n", (double)sizeof(double)); // 8 (64 bit float)
	printf("------------------\n");
	printf("sizeof(size_t): %d\n", (int)sizeof(size_t)); // 8
	printf("sizeof(void *): %d\n", (int)sizeof(void *)); // 8
	printf("------------------\n");
	
	uint8_t temp = 1;
	printf("clear bit 0: %d\n", CLEAR_BIT(temp,0));
	printf("set bit 2: %d\n", SET_BIT(temp,2));
	printf("toggle bit 7: %d\n", TOGGLE_BIT(temp,7));
	if (CHECK_BIT(temp, 7))
		printf("bit 7 got set\n");
	
	printf("clear mask (bits 2 and 7): %d\n", CLEAR_BITMASK(temp, 0x84));
	printf("set mask (bits 1 and 5): %d\n", SET_BITMASK(temp, 0x22));
	printf("u32 swap endianness 0x%08x\n", SWAP_UINT32(0xAA22BB33));
	printf("u16 swap endianness 0x%02x\n", SWAP_UINT16(0xCC11));
}

void bitwise(void)
{
	/*
	typedef unsigned char uint8_t;
	typedef unsigned short uint16_t;
	typedef unsigned long uint32_t;
	typedef unsigned long long uint64_t;
	*/

	unsigned int a = 60;	/* 60 = 0011 1100 */
	unsigned int b = 13;	/* 13 = 0000 1101 */
	int c = 0;
	printf("binary\n");
	printf("a: 0011 1100 == 60\n");
	printf("b: 0000 1101 == 13\n");

	c = a & b;       /* 12 = 0000 1100 */
	printf("AND %d = 0000 1100\n", c);
	c = a | b;       /* 61 = 0011 1101 */
	printf("OR %d = 0011 1101\n", c);
	c = a ^ b;       /* 49 = 0011 0001 */
	printf("XOR %d = 0011 0001\n", c);
	c = ~a;          /*-61 = 1100 0011 */
	printf("NOT %d = 1100 0011\n", c);
	c = a << 2;     /* 240 = 1111 0000 */
	printf("left shift %d = 1111 0000\n", c);
	c = a >> 2;     /* 15 = 0000 1111 */
	printf("right shift %d = 0000 1111\n", c);

	printf("hex\n");
	//0xa7 b9 cc fd
	uint32_t val32 = 0xa7b9ccfd;
	uint8_t val8 = (uint8_t)(0xFF & (val32>>24U) ); // get last byte
	uint8_t val_8 = (uint8_t)(0xFF & (val32>>16U) ); // get next 8 bits
	uint16_t val16 = (uint16_t)( 0XFFFF & val32 );

	printf("val32: %x\n", val32);
	printf("val8 %x - first byte\n", val8);
	printf("val_8 %x - second byte\n", val_8);
	printf("val16 %x - last two bytes\n", val16);

	uint32_t newVar = (uint32_t)( ( (0xcc<<24U)) | (val_8<<16U) | 0xFFFF & (val16) );
	printf("newVar %x - reconstruct bytes\n", newVar);

	uint32_t newVar2 = (uint32_t)( ((0xaa<<24U)) | (0xbb<<16U) | (0xccdd) );
	printf("newVar2 %x - too\n", newVar2);
}

int main() {
	//bitwise();
	test_defines();
	return 0;
}
