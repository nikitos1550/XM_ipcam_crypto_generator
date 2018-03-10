#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define LIBCRYPTV1
//#define LIBCRYPTV2

#ifdef LIBCRYPTV1
int MD5_Init(char *);
int MD5_Update(char *, char *, int);
int MD5_Final(char *, char *);
#endif

#ifdef LIBCRYPTV2
int XM_MD5_Init(char *);
int XM_MD5_Update(char *, char *, int);
int XM_MD5_Final(char *, char *);
#endif

// CRC32 TABLE
unsigned char crc32[] = {0x00,0x00,0x00,0x00,0x96,0x30,0x07,0x77,
0x2c,0x61,0x0e,0xee,0xba,0x51,0x09,0x99,
0x19,0xc4,0x6d,0x07,0x8f,0xf4,0x6a,0x70,
0x35,0xa5,0x63,0xe9,0xa3,0x95,0x64,0x9e,
0x32,0x88,0xdb,0x0e,0xa4,0xb8,0xdc,0x79,
0x1e,0xe9,0xd5,0xe0,0x88,0xd9,0xd2,0x97,
0x2b,0x4c,0xb6,0x09,0xbd,0x7c,0xb1,0x7e,
0x07,0x2d,0xb8,0xe7,0x91,0x1d,0xbf,0x90,
0x64,0x10,0xb7,0x1d,0xf2,0x20,0xb0,0x6a,
0x48,0x71,0xb9,0xf3,0xde,0x41,0xbe,0x84,
0x7d,0xd4,0xda,0x1a,0xeb,0xe4,0xdd,0x6d,
0x51,0xb5,0xd4,0xf4,0xc7,0x85,0xd3,0x83,
0x56,0x98,0x6c,0x13,0xc0,0xa8,0x6b,0x64,
0x7a,0xf9,0x62,0xfd,0xec,0xc9,0x65,0x8a,
0x4f,0x5c,0x01,0x14,0xd9,0x6c,0x06,0x63,
0x63,0x3d,0x0f,0xfa,0xf5,0x0d,0x08,0x8d,
0xc8,0x20,0x6e,0x3b,0x5e,0x10,0x69,0x4c,
0xe4,0x41,0x60,0xd5,0x72,0x71,0x67,0xa2,
0xd1,0xe4,0x03,0x3c,0x47,0xd4,0x04,0x4b,
0xfd,0x85,0x0d,0xd2,0x6b,0xb5,0x0a,0xa5,
0xfa,0xa8,0xb5,0x35,0x6c,0x98,0xb2,0x42,
0xd6,0xc9,0xbb,0xdb,0x40,0xf9,0xbc,0xac,
0xe3,0x6c,0xd8,0x32,0x75,0x5c,0xdf,0x45,
0xcf,0x0d,0xd6,0xdc,0x59,0x3d,0xd1,0xab,
0xac,0x30,0xd9,0x26,0x3a,0x00,0xde,0x51,
0x80,0x51,0xd7,0xc8,0x16,0x61,0xd0,0xbf,
0xb5,0xf4,0xb4,0x21,0x23,0xc4,0xb3,0x56,
0x99,0x95,0xba,0xcf,0x0f,0xa5,0xbd,0xb8,
0x9e,0xb8,0x02,0x28,0x08,0x88,0x05,0x5f,
0xb2,0xd9,0x0c,0xc6,0x24,0xe9,0x0b,0xb1,
0x87,0x7c,0x6f,0x2f,0x11,0x4c,0x68,0x58,
0xab,0x1d,0x61,0xc1,0x3d,0x2d,0x66,0xb6,
0x90,0x41,0xdc,0x76,0x06,0x71,0xdb,0x01,
0xbc,0x20,0xd2,0x98,0x2a,0x10,0xd5,0xef,
0x89,0x85,0xb1,0x71,0x1f,0xb5,0xb6,0x06,
0xa5,0xe4,0xbf,0x9f,0x33,0xd4,0xb8,0xe8,
0xa2,0xc9,0x07,0x78,0x34,0xf9,0x00,0x0f,
0x8e,0xa8,0x09,0x96,0x18,0x98,0x0e,0xe1,
0xbb,0x0d,0x6a,0x7f,0x2d,0x3d,0x6d,0x08,
0x97,0x6c,0x64,0x91,0x01,0x5c,0x63,0xe6,
0xf4,0x51,0x6b,0x6b,0x62,0x61,0x6c,0x1c,
0xd8,0x30,0x65,0x85,0x4e,0x00,0x62,0xf2,
0xed,0x95,0x06,0x6c,0x7b,0xa5,0x01,0x1b,
0xc1,0xf4,0x08,0x82,0x57,0xc4,0x0f,0xf5,
0xc6,0xd9,0xb0,0x65,0x50,0xe9,0xb7,0x12,
0xea,0xb8,0xbe,0x8b,0x7c,0x88,0xb9,0xfc,
0xdf,0x1d,0xdd,0x62,0x49,0x2d,0xda,0x15,
0xf3,0x7c,0xd3,0x8c,0x65,0x4c,0xd4,0xfb,
0x58,0x61,0xb2,0x4d,0xce,0x51,0xb5,0x3a,
0x74,0x00,0xbc,0xa3,0xe2,0x30,0xbb,0xd4,
0x41,0xa5,0xdf,0x4a,0xd7,0x95,0xd8,0x3d,
0x6d,0xc4,0xd1,0xa4,0xfb,0xf4,0xd6,0xd3,
0x6a,0xe9,0x69,0x43,0xfc,0xd9,0x6e,0x34,
0x46,0x88,0x67,0xad,0xd0,0xb8,0x60,0xda,
0x73,0x2d,0x04,0x44,0xe5,0x1d,0x03,0x33,
0x5f,0x4c,0x0a,0xaa,0xc9,0x7c,0x0d,0xdd,
0x3c,0x71,0x05,0x50,0xaa,0x41,0x02,0x27,
0x10,0x10,0x0b,0xbe,0x86,0x20,0x0c,0xc9,
0x25,0xb5,0x68,0x57,0xb3,0x85,0x6f,0x20,
0x09,0xd4,0x66,0xb9,0x9f,0xe4,0x61,0xce,
0x0e,0xf9,0xde,0x5e,0x98,0xc9,0xd9,0x29,
0x22,0x98,0xd0,0xb0,0xb4,0xa8,0xd7,0xc7,
0x17,0x3d,0xb3,0x59,0x81,0x0d,0xb4,0x2e,
0x3b,0x5c,0xbd,0xb7,0xad,0x6c,0xba,0xc0,
0x20,0x83,0xb8,0xed,0xb6,0xb3,0xbf,0x9a,
0x0c,0xe2,0xb6,0x03,0x9a,0xd2,0xb1,0x74,
0x39,0x47,0xd5,0xea,0xaf,0x77,0xd2,0x9d,
0x15,0x26,0xdb,0x04,0x83,0x16,0xdc,0x73,
0x12,0x0b,0x63,0xe3,0x84,0x3b,0x64,0x94,
0x3e,0x6a,0x6d,0x0d,0xa8,0x5a,0x6a,0x7a,
0x0b,0xcf,0x0e,0xe4,0x9d,0xff,0x09,0x93,
0x27,0xae,0x00,0x0a,0xb1,0x9e,0x07,0x7d,
0x44,0x93,0x0f,0xf0,0xd2,0xa3,0x08,0x87,
0x68,0xf2,0x01,0x1e,0xfe,0xc2,0x06,0x69,
0x5d,0x57,0x62,0xf7,0xcb,0x67,0x65,0x80,
0x71,0x36,0x6c,0x19,0xe7,0x06,0x6b,0x6e,
0x76,0x1b,0xd4,0xfe,0xe0,0x2b,0xd3,0x89,
0x5a,0x7a,0xda,0x10,0xcc,0x4a,0xdd,0x67,
0x6f,0xdf,0xb9,0xf9,0xf9,0xef,0xbe,0x8e,
0x43,0xbe,0xb7,0x17,0xd5,0x8e,0xb0,0x60,
0xe8,0xa3,0xd6,0xd6,0x7e,0x93,0xd1,0xa1,
0xc4,0xc2,0xd8,0x38,0x52,0xf2,0xdf,0x4f,
0xf1,0x67,0xbb,0xd1,0x67,0x57,0xbc,0xa6,
0xdd,0x06,0xb5,0x3f,0x4b,0x36,0xb2,0x48,
0xda,0x2b,0x0d,0xd8,0x4c,0x1b,0x0a,0xaf,
0xf6,0x4a,0x03,0x36,0x60,0x7a,0x04,0x41,
0xc3,0xef,0x60,0xdf,0x55,0xdf,0x67,0xa8,
0xef,0x8e,0x6e,0x31,0x79,0xbe,0x69,0x46,
0x8c,0xb3,0x61,0xcb,0x1a,0x83,0x66,0xbc,
0xa0,0xd2,0x6f,0x25,0x36,0xe2,0x68,0x52,
0x95,0x77,0x0c,0xcc,0x03,0x47,0x0b,0xbb,
0xb9,0x16,0x02,0x22,0x2f,0x26,0x05,0x55,
0xbe,0x3b,0xba,0xc5,0x28,0x0b,0xbd,0xb2,
0x92,0x5a,0xb4,0x2b,0x04,0x6a,0xb3,0x5c,
0xa7,0xff,0xd7,0xc2,0x31,0xcf,0xd0,0xb5,
0x8b,0x9e,0xd9,0x2c,0x1d,0xae,0xde,0x5b,
0xb0,0xc2,0x64,0x9b,0x26,0xf2,0x63,0xec,
0x9c,0xa3,0x6a,0x75,0x0a,0x93,0x6d,0x02,
0xa9,0x06,0x09,0x9c,0x3f,0x36,0x0e,0xeb,
0x85,0x67,0x07,0x72,0x13,0x57,0x00,0x05,
0x82,0x4a,0xbf,0x95,0x14,0x7a,0xb8,0xe2,
0xae,0x2b,0xb1,0x7b,0x38,0x1b,0xb6,0x0c,
0x9b,0x8e,0xd2,0x92,0x0d,0xbe,0xd5,0xe5,
0xb7,0xef,0xdc,0x7c,0x21,0xdf,0xdb,0x0b,
0xd4,0xd2,0xd3,0x86,0x42,0xe2,0xd4,0xf1,
0xf8,0xb3,0xdd,0x68,0x6e,0x83,0xda,0x1f,
0xcd,0x16,0xbe,0x81,0x5b,0x26,0xb9,0xf6,
0xe1,0x77,0xb0,0x6f,0x77,0x47,0xb7,0x18,
0xe6,0x5a,0x08,0x88,0x70,0x6a,0x0f,0xff,
0xca,0x3b,0x06,0x66,0x5c,0x0b,0x01,0x11,
0xff,0x9e,0x65,0x8f,0x69,0xae,0x62,0xf8,
0xd3,0xff,0x6b,0x61,0x45,0xcf,0x6c,0x16,
0x78,0xe2,0x0a,0xa0,0xee,0xd2,0x0d,0xd7,
0x54,0x83,0x04,0x4e,0xc2,0xb3,0x03,0x39,
0x61,0x26,0x67,0xa7,0xf7,0x16,0x60,0xd0,
0x4d,0x47,0x69,0x49,0xdb,0x77,0x6e,0x3e,
0x4a,0x6a,0xd1,0xae,0xdc,0x5a,0xd6,0xd9,
0x66,0x0b,0xdf,0x40,0xf0,0x3b,0xd8,0x37,
0x53,0xae,0xbc,0xa9,0xc5,0x9e,0xbb,0xde,
0x7f,0xcf,0xb2,0x47,0xe9,0xff,0xb5,0x30,
0x1c,0xf2,0xbd,0xbd,0x8a,0xc2,0xba,0xca,
0x30,0x93,0xb3,0x53,0xa6,0xa3,0xb4,0x24,
0x05,0x36,0xd0,0xba,0x93,0x06,0xd7,0xcd,
0x29,0x57,0xde,0x54,0xbf,0x67,0xd9,0x23,
0x2e,0x7a,0x66,0xb3,0xb8,0x4a,0x61,0xc4,
0x02,0x1b,0x68,0x5d,0x94,0x2b,0x6f,0x2a,
0x37,0xbe,0x0b,0xb4,0xa1,0x8e,0x0c,0xc3,
0x1b,0xdf,0x05,0x5a,0x8d,0xef,0x02,0x2d};

unsigned char output[1024];

unsigned int l32(unsigned char input[], unsigned int offset) {
	unsigned int tmp;
	tmp = input[offset + 3] << 24;
	tmp = tmp + (input[offset + 2] << 16);
	tmp = tmp + (input[offset + 1] << 8);
	tmp = tmp + input[offset];
	return tmp;
}

void _l32(unsigned int x, unsigned char b[]) {
	b[0] = x 		& 0xff;
	b[1] = (x >> 8) 	& 0xff;
	b[2] = (x >> 16) 	& 0xff;
	b[3] = (x >> 24) 	& 0xff;
}

unsigned int t16(unsigned char input[], unsigned int start, unsigned int num) {
	unsigned int crc = 0xffffffff;
	unsigned int i;
	unsigned int ip;
	for(i=start; i < (start+num); i++) {
		ip = (input[i] ^ crc); //& low32
		ip = (ip & 255); //& low32
		ip = l32(crc32, (ip << 2));
		crc = (crc >> 8) ^ ip; //# & low32 # eor	r2, ip, r2, lsr #8
	}
	return ~crc;
}

int main(int argc, char *argv[]) {
	//unsigned char mac[6] = {0x00, 0x74, 0x69, 0x76, 0x65, 0x6f};
	//unsigned char mac[6] = {0x00, 0x12, 0x13, 0x02, 0xae, 0xf9};

	unsigned int r, i, s;

	#ifdef CMOS_AR030
	//AR030
	unsigned char bloc1[64] = {
		0x0f, 0x33, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x10, 0x90, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x15, 0x14, 0x13, 0x12,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01};
	#endif
	#ifdef CMOS_IMX122_FM
	//Sony imx122/222/322 with FM chip
	unsigned char bloc1[64] = {
		0x8f, 0x73, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x15, 0x14, 0x13, 0x12,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01};
	#endif
	#ifdef CMOS_IMX122
	//Sony imx122/222/322 NO FM chip
	unsigned char bloc1[64] = {
        	0x8f, 0x7c, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
  		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  		0x00, 0x00, 0x00, 0x00, 0x15, 0x14, 0x13, 0x12,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
  		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
  		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01};
	#endif
	#ifdef CMOS_IMX122_NEW
	unsigned char bloc1[64] = {
        	0x90, 0x92, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x15, 0x14, 0x13, 0x12,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01};
	#endif
	#ifdef CMOS_IMX278_FM
	//NightVision Sony imx278 with FM chip
	unsigned char bloc1[64] = {
        	0x0f, 0xfc, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
  		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  		0x00, 0x00, 0x00, 0x00, 0x15, 0x14, 0x13, 0x12,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
  		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01,
  		0x67, 0x45, 0x23, 0x01, 0x67, 0x45, 0x23, 0x01};
	#endif

	unsigned char bloc2[64] = {
		0x10, 0x00, 0x01, 0x00, 0x01, 0x08, 0x00, 0x01,
		0x08, 0x02, 0x00, 0x00, 0xdb, 0x08, 0x00, 0x01,  
		0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,   
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00};
	unsigned char bloc3[64] = {
		0x01, 0x10, 0x00, 0x11, 0x40, 0x10, 0x02, 0x02,
		0x08, 0x00, 0x46, 0x11, 0x00, 0x00, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00};
	unsigned char bloc4[64] = {
		0x01, 0x01, 0x01, 0x15, 0x01, 0x18, 0x00, 0x19,
		0x01, 0x46, 0x00, 0x12, 0x01, 0x00, 0x11, 0x11,  
		0x41, 0x44, 0x50, 0x11, 0xa1, 0x03, 0x06, 0x0a,
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00,  
		0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x00, 0x00};
	

	unsigned char tmp[120];
	unsigned char crc[4];

	unsigned char mac[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	
	unsigned char mactmp[3] = {'f', 'f', '\0'};
	unsigned char macstr[18];//aa:aa:aa:aa:aa:aa
	macstr[17] = '\0';	

	unsigned char macfile[24] = {	'.', '/', 
					'f', 'f', '-',
					'f', 'f', '-', 
					'f', 'f', '-',
					'f', 'f', '-',
					'f', 'f', '-',
					'f', 'f',
					'.', 'e', 'n', 'c', '\0'};//./aa:aa:aa:aa:aa:aa.enc

	printf("XM encryption tool V1.\n");

 	if (argc != 2) {
		/* We print argv[0] assuming it is the program name */
		printf( "usage: %s mac\n", argv[0] );
		return 1;
    	}

	for (i=0;i<17;i++) {
		macstr[i] = argv[1][i];
	}

	s=0;	
	for(i=2;i<19;i=i+3) {
		macfile[i]	= macstr[i-2];
		macfile[i+1]	= macstr[i-1];

		mactmp[0]	= macstr[i-2];
		mactmp[1]	= macstr[i-1];
		mac[s] = strtol(mactmp, NULL, 16);;
		s++;
	}

	printf("Output file is %s.\n", macfile);

	FILE *fp = fopen(macfile, "w" );
	if (fp == 0) {
		printf("Could not open file for write.\n");
		return 1;
	}

	printf("Required MAC: %02x:%02x:%02x:%02x:%02x:%02x.\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	
	//Store MAC to 1st block 
	bloc1[4] 	= mac[0] + 1;
	bloc1[5] 	= mac[1] + 3;
	bloc1[6] 	= mac[2] + 5;
	bloc1[7] 	= mac[3] + 7;
	bloc1[8] 	= mac[4] + 9;
	bloc1[9] 	= mac[5] + 11;
	
	//Randomization
	
	srand(mac[0]+mac[1]+mac[2]+mac[3]+mac[4]+mac[5]);

	bloc4[4] = rand() & 0xFF;
	bloc4[5] = rand() & 0xFF;
	bloc4[6] = rand() & 0xFF; 
	bloc4[7] = rand() & 0xFF; 
	bloc4[8] = rand() & 0xFF; 
	bloc4[9] = rand() & 0xFF; 

	for (i=31;i<64;i++) {
		bloc1[i] = rand() & 0xFF;
	}

	for (i=31;i<64;i++) {
		bloc2[i] = rand() & 0xFF;
	}

	for (i=31;i<64;i++) {
		bloc3[i] = rand() & 0xFF;
	}
	
	for (i=31;i<64;i++) {
		bloc4[i] = rand() & 0xFF;
	}
	
	//Place blocks to 1024 bytes output
	memcpy(&output[0x18],  bloc1, 0x40);
	memcpy(&output[0x138], bloc2, 0x40);
	memcpy(&output[0x258], bloc3, 0x40);
	memcpy(&output[0x378], bloc4, 0x40);

	//Calc XOR
	for (i=0;i<64;i++) {
		output[0x98 + i] = output[0x18 + i] ^ 0xa5;
	}
	for (i=0;i<64;i++) {
		output[0x1b8 + i] = output[0x138 + i] ^ 0xa5;
	}
	for (i=0;i<64;i++) {
		output[0x2d8 + i] = output[0x258 + i] ^ 0xa5;
	}

	for (i=0;i<8;i++) {
		output[0x3ee + i] = output[0x378 + i] ^ 0xa5;
	}

	//Calc MD5 and T.16

	#ifdef LIBCRYPTV1
	MD5_Init(tmp);
	MD5_Update(tmp, &output[0x18], 0x40);
	MD5_Final(&tmp[0x68], tmp);
	#endif
        #ifdef LIBCRYPTV2
        XM_MD5_Init(tmp);
        XM_MD5_Update(tmp, &output[0x18], 0x40);
        XM_MD5_Final(&tmp[0x68], tmp);
        #endif

	memcpy(&output[0x58], &tmp[0x68], 8);
	output[0x57] = output[0x57] + 1; 
	
	i = t16(output, 0x138, 0x40);
	//printf("CRC bloc 2 = 0x%x\n", i);
	_l32(i, crc);
	//printf("0x%x 0x%x 0x%x 0x%x\n", crc[0], crc[1], crc[2], crc[3]);
	memcpy(&output[0x178], crc, 4);
	output[0x176] = output[0x176] + 1; 

	i = t16(output, 0x258, 0x40);
	//printf("CRC bloc 3 = 0x%x\n", i);
	_l32(i, crc);
	//printf("0x%x 0x%x 0x%x 0x%x\n", crc[0], crc[1], crc[2], crc[3]);
	memcpy(&output[0x298], crc, 4);
	output[0x295] = output[0x295] + 1;

	#ifdef LIBCRYPTV1
	MD5_Init(tmp);
	MD5_Update(tmp, &output[0x378], 0x40);
	MD5_Final(&tmp[0x68], tmp);
	#endif
        #ifdef LIBCRYPTV2
        XM_MD5_Init(tmp);
        XM_MD5_Update(tmp, &output[0x378], 0x40);
        XM_MD5_Final(&tmp[0x68], tmp);
        #endif


	memcpy(&output[0x3b8], &tmp[0x68], 8);
	output[0x3b4] = output[0x3b4] + 1;

	//Fill empty with random

	//Fill 1st and 2nd with 0xd2 0xd4
	output[0] = 0xd2;
	output[1] = 0xd4;

	//Swap MAC between bloc 1 and bloc 4
	for(i=0; i<6; i++) {
		s = output[28 + i];
		output[28 + i] = output[889 + (i*2)];
		output[889 + (i*2)] = s;	
	}

	//Calc overall T.16  
	i = t16(output, 0x0, 1020);
	//printf("CRC overall = 0x%x\n", i);
	_l32(i, crc);
	//printf("0x%x 0x%x 0x%x 0x%x\n", crc[0], crc[1], crc[2], crc[3]);
	memcpy(&output[1020], crc, 4);

	//printf("Output:\n");
	s = 0;
	for(i=0;i<1024;i++) {
	//	if (s == 8) { printf("\n"); s = 0; }
	//	printf("0x%x\t", output[i]);
		s++;
		fputc(output[i], fp);
	}
	printf("Complete!\n");
	
	fclose(fp);

	return 0;
}
/*AR030 ???*/
/*
				   0f 33 01 00 01 00 00 00  
00000020  00 00 00 00 10 90 00 00  00 00 00 00 00 00 00 00  
00000030  00 00 00 00 15 14 13 12  67 45 23 01 67 45 23 01
00000040  67 45 23 01 67 45 23 01  67 45 23 01 67 45 23 01
00000050  67 45 23 01 67 45 23 01

 				   10 00 01 00 01 04 01 01 
00000140  08 02 00 00 92 0e 00 01  00 00 00 01 00 00 00 00 
00000150  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00 
00000160  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00 
00000170  00 00 00 00 00 00 00 00

				   01 10 00 11 40 10 02 02
00000260  08 00 46 11 00 00 00 00  00 00 00 00 00 00 00 00
00000270  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00000280  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00000290  00 00 00 00 00 00 00 00

				   01 01 01 15 01 18 00 09
00000380  01 b7 00 04 01 00 11 11  41 44 50 11 a1 03 06 0a
00000390  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
000003a0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
000003b0  00 00 00 00 00 00 00 00
*/

/*Sony imx122/222/322 with FM chip*/
/*
				   8f 73 01 00 01 00 00 00
00000020  00 00 00 00 10 38 00 00  00 00 00 00 00 00 00 00
00000030  00 00 00 00 15 14 13 12  67 45 23 01 67 45 23 01
00000040  67 45 23 01 67 45 23 01  67 45 23 01 67 45 23 01
00000050  67 45 23 01 67 45 23 01  

				   10 00 01 00 01 08 00 01
00000140  08 02 00 00 db 08 00 01  00 00 00 01 00 00 00 00
00000150  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00000160  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00000170  00 00 00 00 00 00 00 00  

				   01 10 00 11 40 10 02 02
00000260  08 00 46 11 00 00 00 00  00 00 00 00 00 00 00 00
00000270  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00000280  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00000290  00 00 00 00 00 00 00 00  

				   01 01 01 15 01 18 00 19
00000380  01 46 00 12 01 00 11 11  41 44 50 11 a1 03 06 0a
00000390  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
000003a0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
000003b0  00 00 00 00 00 00 00 00
*/

/*NightVision Sony imx278 with FM chip*/
/*
00000010   			   0f fc 01 00 01 00 00 00
00000020  00 00 00 00 10 38 00 00  00 00 00 00 00 00 00 00
00000030  00 00 00 00 15 14 13 12  67 45 23 01 67 45 23 01
00000040  67 45 23 01 67 45 23 01  67 45 23 01 67 45 23 01
00000050  67 45 23 01 67 45 23 01  

				   10 00 01 00 01 08 00 01
00000140  08 02 00 00 db 08 00 01  00 00 00 01 00 00 00 00
00000150  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00000160  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00000170  00 00 00 00 00 00 00 00

				   01 10 00 11 40 10 02 02  
00000260  08 00 46 11 00 00 00 00  00 00 00 00 00 00 00 00  
00000270  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  
00000280  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  
00000290  00 00 00 00 00 00 00 00  

				   01 01 01 15 01 18 00 30  
00000380  01 34 00 05 01 00 11 11  41 44 50 11 a1 03 06 0a  
00000390  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  
000003a0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  
000003b0  00 00 00 00 00 00 00 00  
*/

/*Sony imx122/222/322 NO FM chip*/ 
/*
			      8f 7c 01 00 01 00 00 00
020  00 00 00 00 10 38 00 00  00 00 00 00 00 00 00 00
030  00 00 00 00 15 14 13 12  67 45 23 01 67 45 23 01
040  67 45 23 01 67 45 23 01  67 45 23 01 67 45 23 01
050  67 45 23 01 67 45 23 01 

			      10 00 01 00 01 08 00 01
140  08 02 00 00 db 08 00 01  00 00 00 01 00 00 00 00
150  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
160  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
170  00 00 00 00 00 00 00 00 

			      01 10 00 11 40 10 02 02
260  08 00 46 11 00 00 00 00  00 00 00 00 00 00 00 00
270  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
280  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
290  00 00 00 00 00 00 00 00  

			      01 01 01 15 01 18 00 37
380  01 cd 00 9b 01 00 11 11  41 44 50 11 a1 03 06 0a
390  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
3a0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
3b0  00 00 00 00 00 00 00 00  
*/

/*Sony IMX122/222/322 NEW*/
/*
			 90 92 01 00 01 00 00 00
00 00 00 00 10 38 00 00  00 00 00 00 00 00 00 00
00 00 00 00 15 14 13 12  67 45 23 01 67 45 23 01
67 45 23 01 67 45 23 01  67 45 23 01 67 45 23 01
67 45 23 01 67 45 23 01

			 10 00 01 00 01 08 00 01
08 02 00 00 db 08 00 01  00 00 00 01 00 00 00 00
00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00

			 01 10 00 11 40 10 02 02
08 00 46 11 00 00 00 00  00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00

			 01 01 01 15 01 1b 00 82
01 01 00 1e 01 00 11 11	 41 44 50 11 a1 03 06 0a
00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
*/
/////////////////////////////////////////////////////
/*
000 * * * * * * * *	* * * * * * * *
010 * * * * * * * *    [d d d d M M M M
020 M M d d d d d d	d d d d d d d d
030 d d d d d d d d	d d d d d d d d
040 d d d d d d d d	d d d d d d d d
050 d d d d d d d d]	MD5 hash block1
060 * * * * * * * *	* * * * * * * *
070 * * * * * * * *	* * * * * * * *
080 * * * * * * * *	* * * * * * * *
090 * * * * * * * *	X X X X X X X X
0a0 X X X X X X X X	X X X X X X X X
0b0 X X X X X X X X	X X X X X X X X
0c0 X X X X X X X X	X X X X X X X X
0d0 X X X X X X X X	* * * * * * * *
0e0 * * * * * * * *	* * * * * * * *
0f0 * * * * * * * *	* * * * * * * *
100 * * * * * * * *	* * * * * * * *
110 * * * * * * * *	* * * * * * * *
120 * * * * * * * *	* * * * * * * *
130 * * * * * * * *    [d d d d d d d d
140 d d d d d d d d	d d d d d d d d
150 d d d d d d d d	d d d d d d d d
160 d d d d d d d d	d d d d d d d d
170 d d d d d d d d]	CRC T16 * * * *
180 * * * * * * * *	* * * * * * * *
190 * * * * * * * *	* * * * * * * *
1a0 * * * * * * * *	* * * * * * * *
1b0 * * * * * * * *	X X X X X X X X
1c0 X X X X X X X X	X X X X X X X X
1d0 X X X X X X X X	X X X X X X X X
1e0 X X X X X X X X	X X X X X X X X
1f0 X X X X X X X X	* * * * * * * *
200 * * * * * * * *	* * * * * * * *
210 * * * * * * * *	* * * * * * * *
220 * * * * * * * *	* * * * * * * *
230 * * * * * * * *	* * * * * * * *
240 * * * * * * * *	* * * * * * * *
250 * * * * * * * *    [d d d d d d d d
260 d d d d d d d d	d d d d d d d d
270 d d d d d d d d	d d d d d d d d
280 d d d d d d d d	d d d d d d d d
290 d d d d d d d d]	CRC T16 * * * *
2a0 * * * * * * * *	* * * * * * * *
2b0 * * * * * * * *	* * * * * * * *
2c0 * * * * * * * *	* * * * * * * *
2d0 * * * * * * * *	X X X X X X X X
2e0 X X X X X X X X	X X X X X X X X
2f0 X X X X X X X X	X X X X X X X X
300 X X X X X X X X	X X X X X X X X
310 X X X X X X X X	* * * * * * * *
320 * * * * * * * *	* * * * * * * *
330 * * * * * * * *	* * * * * * * *
340 * * * * * * * *	* * * * * * * *
350 * * * * * * * *	* * * * * * * *
360 * * * * * * * *	* * * * * * * *
370 * * * * * * * *    [d m d m d m d m
380 d m d m d d d d	d d d d d d d d
390 d d d d d d d d	d d d d d d d d
3a0 d d d d d d d d	d d d d d d d d
3b0 d d d d d d d d]	MD5 hash block4
3c0 * * * * * * * *	* * * * * * * *
3d0 * * * * * * * *	* * * * * * * *
3e0 * * * * * * * *	* * * * * * * *
3f0 * * * * * * * *	* * * * CRC T16
*/
