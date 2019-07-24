#include "TLPI_include.h"

void func1(int sig) {
  printf("%d\n", sig);
}

int main(int argc, char* argv[])
{
  if(argc != 1 || argv[1] == "--help"){
    usageInfo("%s\n", argv[0]);
  }
  int fd = fork();
  if(fd == 0) {
    printf("child: %d\n", getpid());
    //child
    struct sigaction sigstruc;
    memset(&sigstruc, 0, sizeof(sigstruc));
    sigfillset(&sigstruc.sa_mask);
    sigstruc.sa_handler = func1;
    if(sigaction(SIGABRT,&sigstruc,NULL) == -1) {
      errorExit("sigaction");
    }
    sigstruc.sa_handler = SIG_DFL;
    if(sigaction(SIGABRT,&sigstruc,NULL) == -1) {
      errorExit("sigaction");
    }
    while(1) 
      // pause();
      printf("%d\n", getppid());
  } else if (fd > 0) {
    //parent
    // int status, ret;
    // while(1) {
    //   while((ret = waitpid(fd, &status, WNOHANG | WUNTRACED | WCONTINUED)) == 0) ;
    //   if(ret == -1) {
    //     errorExit("waitpid");
    //   }
    //   printf("%d:%d:%d:%d\n", WIFEXITED(status),WIFSIGNALED(status),
    //     WIFSTOPPED(status), WIFCONTINUED(status));
    // }
  } else {
    errorExit("error in fork\n");
  }
  return 0;
}
