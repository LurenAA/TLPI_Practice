#include "TLPI_include.h"
extern char **environ;

int main(int argc, char* argv[])
{
  char **ep = environ;
  *ep = "ASdasd";
  for(int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
  return 0;
}
