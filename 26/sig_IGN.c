#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  struct sigaction sigstruc;
  memset(&sigstruc, 0, sizeof(sigstruc));
  sigemptyset(&sigstruc.sa_mask);
  sigstruc.sa_handler = SIG_IGN;
  if(sigaction(SIGCHLD,&sigstruc, NULL) == -1) {
    errorExit("error in sigaction");
  }
  // sigset_t sigset, befor;
  // sigemptyset(&sigset);
  // sigaddset(&sigset, SIGCHLD);
  // if(sigprocmask(SIG_SETMASK, &sigset, &befor) == -1) {
  //   errorExit("Err in sigproc");
  // }

  for(int i = 0; i< 10; i++) {
    int fd = fork();
    if(fd < 0) {
      errorExit("err in fork");
    } else if (fd > 0) {
      sleep(3);
      printf("exit: %d\n", getpid());
      exit(1);
    }
  }
  // if(sigprocmask(SIG_SETMASK, &befor, NULL) == -1) {
  //   errorExit("Err in sigproc");
  // }
  int f = wait(NULL);
  if(f == -1) {
    errorExit("err in wait");
  }

  return 0;
}
