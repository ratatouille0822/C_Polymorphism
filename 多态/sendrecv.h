#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void* pDataHead;

void init_mem(pDataHead *p);
void set_buf(pDataHead p, char *buf, int len);
void get_buf(pDataHead p, char *recv, int *len);
void destroy(pDataHead p);