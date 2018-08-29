#include <stdio.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

main() {
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
	return 0;
}
