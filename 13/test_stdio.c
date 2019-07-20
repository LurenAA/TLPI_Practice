#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  char* buf = (char*)malloc(10);
  memset(buf, 0, 10);
  setvbuf(stdout, buf, _IOFBF, 10);
  fflush(NULL);
  // fprintf(stdout, "abc");
  // fputs("abcde", stdout);
  // sleep(1);
  // fputs("abcde", stdout);
  // sleep(1);
  // fputs("S", stdout);
  // sleep(1);
  for(int i = 0; i < 9; i++) {
    fputc('t',stdout);
  }
  sleep(1);
  fputc('t',stdout);
  fprintf(stderr, "End\n");
  return 0;
}