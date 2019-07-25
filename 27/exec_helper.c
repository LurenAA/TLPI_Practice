#include "TLPI_include.h"
extern char **environ;

int main(int argc, char* argv[])
{
  char **ep = environ;
  printf("%d:%d\n", getuid(), geteuid());
  for(int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
  return 0;
}
