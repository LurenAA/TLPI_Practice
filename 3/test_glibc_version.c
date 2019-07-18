#include <unistd.h>
#include <stdio.h>
#include <gnu/libc-version.h>
#include <string.h>
#include <errno.h>

int main(void) {
  printf("version: %d : %d\n", __GLIBC__, __GLIBC_MINOR__);
  printf("version: %s\n", gnu_get_libc_version());
  const char* p2Erorr;
  p2Erorr = strerror(E2BIG);
  if(p2Erorr)
    printf("ErrorStr: %s\n", p2Erorr);
  p2Erorr = strerror(EACCES);
  if(p2Erorr)
    printf("ErrorStr: %s\n", p2Erorr);
  return 0;
}