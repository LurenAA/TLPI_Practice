#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  siginfo_t info;
  sigset_t sigset;
  sigemptyset(&sigset);
  sigaddset(&sigset, SIGTERM);
  if(sigprocmask(SIG_SETMASK, &sigset, NULL) == -1) {
    errorExit("error  in sigprocmask\n");
  }
  printf("begin sigwaitinfo: %d\n", getpid());
  int sig = sigwaitinfo(&sigset, &info);
  if(sig == -1) {
    errorExit("error in sigwaitinfo");
  }
  printf("suc: %d\n", sig);

  return 0;
}
