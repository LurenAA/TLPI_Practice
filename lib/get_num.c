#include "TLPI_include.h"

static void 
error_detect(long long a) {
  if(a == LONG_MAX || a == LONG_MIN 
  || a == LLONG_MAX || a== LLONG_MIN || a == 0) 
  {
    errorExit("translate str to long/llong error");
  }
}

long 
get_long_dec(const char*  str) {
  char *end;
  long res = strtol(str, &end, 10);
  error_detect(res);
  return res;
}

long 
get_long_hex(const char*  str) {
  char *end;
  long res = strtol(str, &end, 16);
  error_detect(res);
  return res;
}
