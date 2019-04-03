#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "sendrecv.h"

typedef struct _data
{
	char *buf;
	int len;

}DATA;

void init_mem(pDataHead *p)
{
	*p = malloc(sizeof(DATA));
	return;
}
void set_buf(pDataHead p1, char *buf, int len)
{
	DATA *p = (DATA *)p1;
	p->buf = malloc(len + 1);
	p->len = len;
	strcpy(p->buf, buf);

}
void get_buf(pDataHead p1, char *recv, int *len)
{
	DATA *p = (DATA *)p1;
	strcpy(recv, p->buf);
	*len = p->len;

}
void destroy(pDataHead p1)
{
	DATA *p = (DATA *)p1;
	free(p->buf);
	free(p);
}

