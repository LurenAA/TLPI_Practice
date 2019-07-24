#include "TLPI_include.h"

void sigHandler(int sig) {
  int savedErrno = errno,
    status, pid;
  while((pid = waitpid(-1, &status, WNOHANG)) > 0) {
    printf("sighandle : %d\n", pid);
  }
  if(pid < 0) {
    errorExit("error in waitpid");
  }

  errno = savedErrno;
}

int main(int argc, char* argv[])
{
  if(argc < 3 || argv[1] == "--help"){
    usageInfo("%s\n sleepTime forkNums", argv[0]);
  }
  struct sigaction sigStruc;
  memset(&sigStruc, 0, sizeof(sigStruc));
  sigemptyset(&sigStruc.sa_mask);
  sigStruc.sa_handler = sigHandler;
  if(sigaction(SIGCHLD, &sigStruc, NULL) < 0) {
    errorExit("error in sigaction");
  }
  sigset_t sigSet;
  sigemptyset(&sigSet);
  sigaddset(&sigSet, SIGCHLD);
  if(sigprocmask(SIG_BLOCK, &sigSet, NULL) < 0) {
    errorExit("error in sigprocmask");
  }

  int numb = get_long_dec(argv[2]);
  int sltime = get_long_dec(argv[1]);

  for(int i = 0; i < numb; ++i) {
    int fd = fork();
    if(fd < 0) {
      errorExit("error in fork");
    } else if (fd == 0) {
      sleep(sltime);
      _exit(1);
    } 
  }

  for(;;) {
    sigset_t empset;
    sigemptyset(&empset);
    int rse = sigsuspend(&empset);
    if(rse == -1) {
      printf("sigsuspend\n");
    }
  }

  return 0;
}
