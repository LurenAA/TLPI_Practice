#include "TLPI_include.h"

void func1() {
  printf("func1\n");
}

void func2(int status , void* arg) {
  printf("%d:%d\n", status, (long)arg);
} 

int main(int argc, char* argv[])
{
  // printf("!2312");
  // atexit(func1);

  // on_exit(func2, (void*)20);
  int i = wait(NULL);
  printf("%d", i);

  // fork();
  exit(1);
}
