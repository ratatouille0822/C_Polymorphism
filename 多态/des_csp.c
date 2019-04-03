#include "des_csp.h"


int SetActualDesFunctions(EncryptInstence* encrypt_instence, pDesEnc des_encrypt, pDesDec des_decode)
{
	encrypt_instence->des_encrypt = des_encrypt;
	encrypt_instence->des_decode = des_decode;

}
