#pragma once


typedef int (*pDesEnc)(
		unsigned char *pInData,
		int            nInDataLen,
		unsigned char *pOutData,
		int           *pOutDataLen);

typedef int (*pDesDec)(
	unsigned char *pInData,
	int            nInDataLen,
	unsigned char *pOutData,
	int           *pOutDataLen);


typedef struct EncryptInstence
{
	pDesEnc des_encrypt;
	pDesDec des_decode;

}EncryptInstence;


int SetActualDesFunctions(EncryptInstence* encrypt_instence, pDesEnc des_encrypt, pDesDec des_decode);