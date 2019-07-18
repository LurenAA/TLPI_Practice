#ifndef __ERROR_HANDLE_H_
#define __ERROR_HANDLE_H_

#include <stdarg.h>
#include <stdio.h>
#include <ename.c.inc>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void errorExit(const char* format, ...);
void usageInfo(const char* format, ...);

#endif