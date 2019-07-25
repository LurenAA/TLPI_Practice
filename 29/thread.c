#include "TLPI_include.h"
int loc = 0;
pthread_mutex_t mutex ;//= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond;// = PTHREAD_COND_INITIALIZER;
pthread_once_t once_var = PTHREAD_ONCE_INIT;

void init() {
  printf("init\n");
}

void* func(void* p) {
  sleep(1);
  pthread_once(&once_var,init);
  pthread_mutex_lock(&mutex);
  for(int i = 0; i <1000;i++) {
    loc++;
  }
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex);
  
  printf("sdas\n");
  return p;
}

int main(int argc, char* argv[])
{
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond,NULL);
  pthread_t thread,thread2;
  // char b[] = "baaa";
  if(pthread_create(&thread, NULL, func, &loc) != 0) {
    errorExit("error in pthread_create\n");
  }
  if(pthread_create(&thread2, NULL, func, &loc) != 0) {
    errorExit("error in pthread_create2\n");
  }
  printf("join\n");
  // sleep(1);
  pthread_mutex_lock(&mutex);
  while(pthread_cond_wait(&cond,&mutex) != 0) ;
  
  pthread_mutex_unlock(&mutex);
  void *rec;
  // pthread_detach(thread);
  int errNum;
  if((errNum = pthread_join(thread, &rec)) != 0) {
    printf("%s:%s\n",ename[errNum], strerror(errNum));
  }
  if((errNum = pthread_join(thread2, &rec)) != 0) {
    printf("%s:%s\n",ename[errNum], strerror(errNum));
  }
  printf("%d\n", loc);
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);
  return 0;
}
