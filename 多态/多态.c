#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "framework.h"
#include "sendrecv.h"
#include "des_csp.h"
#include "des.h"

//#define HERE

int main(void)
{
#ifndef HERE
	CSPInstence csp_instence;
	//GetCSPFuncs(&csp_instence, init_mem, set_buf, get_buf, destroy);
	EncryptInstence encrypt_instence;

	GetCSPFuncsWithEncrtpt(&csp_instence, init_mem, set_buf, get_buf, destroy, &encrypt_instence, DesEnc, DesDec);
	

#endif

#ifdef HERE
	pDataHead p;
	init_mem(&p);
	set_buf(p, "hello", sizeof("hello"));
	char buf[128] = { 0 };
	int len = 0;
	get_buf(p, buf, &len);
	printf("HERE --->%s<---\n", buf);
	destroy(p);
#endif

	return 0;
}
