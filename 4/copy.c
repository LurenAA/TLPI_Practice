#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "error_handle.h"
#define MAX_COPY_BUF 500

int main(int argc, char *argv[])
{
  if(argc != 3 || argv[1] == "--help") {
    usageInfo("%s src_file dest_file", argv[0]);
    exit(1);
  }
  int srcFd = open(argv[1], O_RDONLY, NULL);
  if(srcFd < 0) {
    errorExit("open %s error", argv[1]);
  }
  int destFd = open(argv[2], O_WRONLY | O_CREAT| O_TRUNC, 
    S_IRWXU | S_IRWXG | S_IROTH);
  if(destFd < 0){
    errorExit("open %s error", argv[2]);
  }
  char buf[MAX_COPY_BUF + 1];
  int countNumber = 0;
  while(countNumber = read(srcFd, buf, MAX_COPY_BUF)) {
    if(write(destFd, buf, countNumber) != countNumber) {
      errorExit("write number not equal to read number");
    }
  }
  
  return 0;
}