#pragma once

#include "sendrecv.h"

typedef void (*CSP_INIT)(pDataHead *p);
typedef void (*CSP_SEND)(pDataHead p, char *buf, int len);
typedef void (*CSP_GET)(pDataHead p, char *recv, int *len);
typedef void (*CSP_FREE)(pDataHead p);

typedef struct CSPInstence
{
	CSP_INIT csp_init;
	CSP_SEND csp_send;
	CSP_GET csp_get;
	CSP_FREE csp_free;
}CSPInstence;

int SetActualCSPFunctions(CSPInstence * csp_instence, CSP_INIT csp_init, CSP_SEND csp_send, CSP_GET csp_get, CSP_FREE csp_free);
