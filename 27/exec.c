#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  if(argc < 2 || argv[1] == "--help"){
    usageInfo("%s path [...argv]\n", argv[0]);
  }
  char *c_argv[10];
  char *newOne = (char*)malloc(sizeof("abc"));
  strcpy(newOne, "abc");
  char *p[] = {"a=1", "b=2"};
  // printf("%s\n", newOne);
  c_argv[0] = strrchr(argv[1], '/');
  c_argv[1] = argv[2];
  c_argv[2] = argv[3];
  c_argv[3] = newOne;
  c_argv[4] = NULL;
  // int re = execve(argv[1], c_argv, p);
  int re = execlp(argv[1],c_argv[0],c_argv[1],c_argv[2],c_argv[3],NULL, p);
  if(re == -1 && errno > 0) {
    errorExit("error in execve");
  }

  return 0;
}
