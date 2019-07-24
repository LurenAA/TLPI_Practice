#include "TLPI_include.h"
volatile int alldone = 0;

void 
handler(int sig, siginfo_t *info, void *ucontext)
{
  if(info->si_signo ==  SIGINT || 
    info->si_signo == SIGTERM) {
    alldone = 1;
    printf("all done\n");
  }
  printf("si->signo: %d\n", info->si_signo);
  return ;
}

int main(int argc, char *argv[])
{
  if (argc < 2 || argv[1] == "--help")
  {
    usageInfo("%s time", argv[0]);
  }
  printf("pid: %d, uid: %d, euid:%d\n",
   (int)getpid(), (int)getuid(), (int)geteuid());
  long timeLast = get_long_dec(argv[1]);
  struct sigaction sigstruct;
  memset(&sigstruct, '\0', sizeof(sigstruct));
  sigfillset(&sigstruct.sa_mask);
  sigstruct.sa_flags = SA_SIGINFO;
  sigstruct.sa_sigaction = handler;

  for (int i = 1; i < SIGSYS; ++i){
    if(i == SIGSTOP || i == SIGKILL) {
      continue;
    }
    if(sigaction(i, &sigstruct, NULL) == -1)
      errorExit("error in sigaction in %d", i);
  }
  for (int i = SIGRTMIN; i < NSIG; ++i){
    if(sigaction(i, &sigstruct, NULL) == -1)
      errorExit("error in sigaction in %d", i);
  }
  
  sigset_t sigSet, preSet;
  sigfillset(&sigSet);
  sigdelset(&sigSet, SIGTERM);
  sigdelset(&sigSet, SIGINT);
  if(sigprocmask(SIG_SETMASK, &sigSet, &preSet) == -1) {
    errorExit("error in %s in sigprocmask", argv[0]);
  }
  printf("sleep for %ld s\n", timeLast);
  sleep(timeLast);
  printf("end sleep\n");
  if(sigprocmask(SIG_SETMASK, &preSet, NULL) == -1) {
    errorExit("error in %s in sigprocmask", argv[0]);
  }
  while(!alldone) {
    printf("next pause\n");
    pause();
  }
  return 0;
}
