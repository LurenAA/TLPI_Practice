#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  if(argc != 1 || argv[1] == "--help"){
    usageInfo("%s\n", argv[0]);
  }
  char tmpFile[] = "tmpFileXXXXXX";
  int tmpFileFd = mkstemp(tmpFile);
  if(tmpFileFd == -1) {
    errorExit("error in mkstemp in %s", argv[0]);
  }
  int flags = fcntl(tmpFileFd, F_GETFL);
  printf("O_APPEND: %d\n", flags & O_APPEND);
  int pid = fork();
  if(pid == 0) {
    //child
    flags |= O_APPEND;
    if(fcntl(tmpFileFd, F_SETFL, flags) == -1) {
      errorExit("error fcntl(tmpFileFd, F_SETFL, flags)");
    }
    flags = fcntl(tmpFileFd, F_GETFL);
    printf("O_APPEND: %d\n", flags & O_APPEND);
  } else if (pid > 0) {
    //parent
    if(wait(NULL) == -1)
      errorExit("wait");
    flags = fcntl(tmpFileFd, F_GETFL);
    printf("O_APPEND: %d\n", flags & O_APPEND);
    unlink(tmpFile);
  } else {
    errorExit("error in fork");
  }

  return 0;
}
