#include "TLPI_include.h"
struct timeval getTimeNow, getTime;
void handle(int sig) {
  if(gettimeofday(&getTimeNow, NULL) == -1) {
    errorExit("error in gettimeofday");
  }
  printf("time: %d\n", 
    getTimeNow.tv_sec - getTime.tv_sec);
  return ;
}

int main(int argc, char* argv[])
{
  struct sigaction sigstruc;
  memset(&sigstruc, 0, sizeof(sigstruc));
  if(sigemptyset(&sigstruc.sa_mask) == -1) {
    errorExit("error in sigemptyset");
  }
  sigaddset(&sigstruc.sa_mask, SIGALRM);
  sigstruc.sa_handler = handle;
  if(sigaction(SIGALRM, &sigstruc, NULL) == -1) {
    errorExit("error in sigaction");
  }
  struct itimerval timerConfig;
  timerConfig.it_interval.tv_sec = 0;
  timerConfig.it_interval.tv_usec = 0;
  timerConfig.it_value.tv_sec = 1;
  timerConfig.it_value.tv_usec = 0;
  if(gettimeofday(&getTime, NULL) == -1) {
    errorExit("error in gettimeofday");
  }
  if(setitimer(ITIMER_REAL, &timerConfig, NULL) == -1) {
    errorExit("error in setitimer");
  }
  struct timespec timeCo;
  timeCo.tv_sec = 0;
  timeCo.tv_nsec = 500000000;
  nanosleep(&timeCo, NULL);
  struct itimerval timeGtt;
  getitimer(ITIMER_REAL,&timeGtt);
  printf("%d\n", timeGtt.it_value.tv_usec);


  return 0;
}
