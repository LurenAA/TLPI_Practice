#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  if(argc < 4 || argv[1] == "--help"){
    usageInfo("%s pid signum times", argv[0]);
  }
  long theTime = get_long_dec(argv[3]);
  long sigNum = get_long_dec(argv[2]);
  long pid = get_long_dec(argv[1]);
  union sigval val ;
  val.sival_int = 1;
  for(int i = 0; i < theTime; i++) {
    if(sigqueue(pid,sigNum, val) == -1) {
      errorExit("error in sigqueue");
    }
  }

  return 0;
}
