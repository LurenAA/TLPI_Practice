#include "TLPI_include.h"

void handle(int sig) {
  printf("in handle\n");
}

int main(int argc, char* argv[])
{
  // if(argc < 3 || argv[1] == "--help"){
  //   usageInfo("%s", argv[0]);
  // }
  // signal(SIGTERM, handle);
  struct sigaction sigStruc;
  memset(&sigStruc, '\0', sizeof(sigStruc));
  sigemptyset(&sigStruc.sa_mask);
  sigStruc.sa_handler = handle;
  if(sigaction(SIGTERM, &sigStruc, NULL) == -1) {
    errorExit("error in sigaction");
  }
  sigset_t sigset, pre, aft;
  sigemptyset(&pre);
  sigemptyset(&aft);
  if(sigemptyset(&sigset) == -1)
    errorExit("sigemptyset");
  sigaddset(&sigset, SIGTERM);
  // sigaddset(&sigset, SIGSTKSZ);
  // sigdelset(&sigset, SIGSTKSZ);
  // printf("%d\n", sigismember(&sigset,SIGQUIT));
  if(sigprocmask(SIG_SETMASK, &sigset, &pre) == -1) {
    errorExit("error in sigprocmask");
  }
  fputs("sleep\n",stderr);
  sleep(10);
  // pause();
  if(sigprocmask(SIG_SETMASK, &pre, NULL) == -1) {
    errorExit("error in sigprocmask");
  }
  sleep(1);
  sigpending(&aft);
  printf("%d\n",sigismember(&aft, SIGTERM));
  fputs("end\n",stderr);
  return 0;
}
