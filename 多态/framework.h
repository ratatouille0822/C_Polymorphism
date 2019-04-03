#pragma once
#include "CSocketProtocal.h"
#include "des_csp.h"


int GetCSPFuncs(CSPInstence * csp_instence, CSP_INIT csp_init, CSP_SEND csp_send, CSP_GET csp_get, CSP_FREE csp_free);
int GetCSPFuncsWithEncrtpt(CSPInstence * csp_instence, CSP_INIT csp_init, CSP_SEND csp_send, CSP_GET csp_get, CSP_FREE csp_free,
	EncryptInstence* encrypt_instence, pDesEnc des_encrypt, pDesDec des_decode);
