#include "TLPI_include.h"
void handle(int sig) {
  printf("sig: %s\n", strsignal(sig));
}


int main(int argc, char* argv[])
{
  // int flg;
  // flg = kill(1, 0);
  // if(flg == -1) {
  //   errorExit("%s", argv[0]);
  // }
  signal(SIGURG, handle);
  raise(SIGURG);

  return 0;
}
