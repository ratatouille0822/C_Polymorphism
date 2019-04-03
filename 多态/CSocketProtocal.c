#include "CSocketProtocal.h"



int SetActualCSPFunctions(CSPInstence * csp_instence, CSP_INIT csp_init, CSP_SEND csp_send, CSP_GET csp_get, CSP_FREE csp_free)
{
	csp_instence->csp_init = csp_init;
	csp_instence->csp_get = csp_get;
	csp_instence->csp_send = csp_send;
	csp_instence->csp_free = csp_free;

	return 0;
}
