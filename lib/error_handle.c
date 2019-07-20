#include "error_handle.h"

static void 
sizeErrorHelper(int size) {
  if(size < 0) {
    printf("%s: error in error_handle\n", strerror(errno));
    exit(1);
  }
}

static void 
errorInfoShow(const char* format, va_list vaList) {
#define MAX_BUF_SIZE 500
  int size = 0;
  char buf[MAX_BUF_SIZE], buf2[MAX_BUF_SIZE], buf3[MAX_BUF_SIZE];
  size = vsnprintf(buf, MAX_BUF_SIZE, format, vaList);
  sizeErrorHelper(size);
  size = snprintf(buf2, MAX_BUF_SIZE, "%s:%s", (errno >= 0 && errno < MAX_ENAME) 
    ? ename[errno] : "?UNKNOWN?" , strerror(errno));
  sizeErrorHelper(size);
  size = snprintf(buf3, MAX_BUF_SIZE, "%s>>>>%s\n", buf, buf2);
  sizeErrorHelper(size);
  fputs(buf3, stdout);
  fflush(stdout);
}

void 
errorExit(const char* format, ...) {
  va_list vaList;
  va_start(vaList, format);
  errorInfoShow(format, vaList);
  
  va_end(vaList);
  exit(EXIT_FAILURE);
}

void 
usageInfo(const char* format, ...) {
#define MAX_BUF_SIZE 500
  char buf[MAX_BUF_SIZE];
  va_list vaList;
  fprintf(stderr, "Usage: ");
  va_start(vaList, format);
  int size = vfprintf(stderr, format, vaList);
  sizeErrorHelper(size);  
  fflush(stderr);
  va_end(vaList);
  exit(1);
}