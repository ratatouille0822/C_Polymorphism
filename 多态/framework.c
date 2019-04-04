#include "framework.h"

int GetCSPFuncs(CSPInstence * csp_instence, CSP_INIT csp_init, CSP_SEND csp_send, CSP_GET csp_get, CSP_FREE csp_free)
{
	SetActualCSPFunctions(csp_instence, csp_init, csp_send, csp_get, csp_free);

	pDataHead p;

	csp_instence->csp_init(&p);
	
	char demo[128] = "Hello!";
	csp_instence->csp_send(p, demo, strlen(demo));
	char recv[128] = { 0 };
	int len = 0;
		
	csp_instence->csp_get(p, recv, &len);
	printf("%s\n",recv);
	csp_instence->csp_free(p);

	return 0;

}

int GetCSPFuncsWithEncrtpt(CSPInstence * csp_instence, CSP_INIT csp_init, CSP_SEND csp_send, CSP_GET csp_get, CSP_FREE csp_free,
	EncryptInstence* encrypt_instence, pDesEnc des_encrypt, pDesDec des_decode)
{

	SetActualCSPFunctions(csp_instence, csp_init, csp_send, csp_get, csp_free);
	SetActualDesFunctions(encrypt_instence, des_encrypt, des_decode);

	pDataHead p;

	csp_instence->csp_init(&p);
	
	char demo[4*1024] = "Hello!";
	char buffer[4*1024] = { 0 };
	int length_of_encrypt_string = 0;
	int length_of_plaintext_string = strlen(demo);
	encrypt_instence->des_encrypt(demo, length_of_plaintext_string, buffer, &length_of_encrypt_string);
	csp_instence->csp_send(p, buffer, length_of_encrypt_string);
	char recv[128] = { 0 };
	int len = 0;

	csp_instence->csp_get(p, recv, &len);
	char decode_buffer[128] = { 0 };
	int length_of_decoded_string = 0;
	encrypt_instence->des_decode(recv, len, decode_buffer, &length_of_decoded_string);
	printf("%s\n", decode_buffer);
	csp_instence->csp_free(p);

	return 0;
}
