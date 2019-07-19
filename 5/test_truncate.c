#include "TLPI_include.h"

int main(int argc, char* argv[])
{
#define BUF_SIZE 2000  
  char templateString [] = "atmpXXXXXX";
  int newFd = mkstemp(templateString);
  if(newFd == -1) {
    errorExit("error mkstemp %s", argv[0]);
  }
  char tempArray[BUF_SIZE];
  memset(tempArray, 1, BUF_SIZE);
  // ftruncate(newFd, BUF_SIZE / 2);
  truncate(templateString, BUF_SIZE / 2);
  struct stat buf;
  fstat(newFd, &buf);
  printf("size: %d\n", (int)buf.st_size);
  unlink(templateString);
  
  return 0;
}