#include "TLPI_include.h"

void *start_routine(void * i) {
  for(int i = 0;;i++) {
    sleep(1);
  }
}

int main(int argc, char* argv[])
{
  pthread_t chThread;
  if(pthread_create(&chThread, NULL, start_routine, NULL) != 0) {
    printf("error in pthread_create\n");
    exit(1);
  }
  if(pthread_cancel(chThread) != 0) {
    printf("error in pthread_cancel\n");
    exit(1);
  }
  void * back;
  if(pthread_join(chThread, &back) != 0){
    printf("error in pthread_join\n");
    exit(1);
  }
  if(back == PTHREAD_CANCELED) {
    printf("123123\n");
  }
  return 0;
}
