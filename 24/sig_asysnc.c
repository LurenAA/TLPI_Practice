#include "TLPI_include.h"

void sigHadnle(int sig) {
  printf("sihandle: %d\n", (int)getpid());
}

int main(int argc, char* argv[])
{
  if(argc != 1 || argv[1] == "--help"){
    usageInfo("%s\n", argv[0]);
  }
  sigset_t sigset, oldset;
  sigemptyset(&sigset);
  sigemptyset(&oldset);
  sigaddset(&sigset, SIGUSR1);
  if(sigprocmask(SIG_SETMASK, &sigset, &oldset) == -1) {
    errorExit("error in sigprocmask");
  }
  struct sigaction sigstruc;
  memset(&sigstruc, 0, sizeof(sigstruc));
  sigemptyset(&sigstruc.sa_mask);
  sigstruc.sa_handler = sigHadnle;
  if(sigaction(SIGUSR1, &sigstruc, NULL) == -1) {
    errorExit("error in sigaction");
  }
  pid_t parentPid = getpid();
  int fk = fork();
  if(fk == 0) {
    //child
    printf("child process: %d\n", (int)getpid());
    sleep(2);
    if(kill(parentPid, SIGUSR1) == -1) {
      errorExit("error in kill");
    }
    exit(EXIT_SUCCESS);
  } else if(fk > 0) {
    //parent
    printf("parent process: %d\n", (int)getpid());
    sigset_t tmpSet;
    sigfillset(&tmpSet);
    sigdelset(&tmpSet, SIGUSR1);
    sigsuspend(&tmpSet);
    printf("wait\n");
    wait(NULL);
  } else {
    errorExit("error in fork");
  }

  return 0;
}
