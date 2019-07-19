#include "TLPI_include.h"

int main(int argc, char* argv[])
{
#define READ_SIZE 20
#define OFF_SIZE 10
  if(argc != 2 || argv[1] == "--help") {
    usageInfo("%s file1", argv[0]);
    exit(1);
  }
  int fd = open(argv[1], O_RDONLY);
  off_t off = lseek(fd, 0, SEEK_SET);
  printf("begin: %d\n", (int)off);
  char buf[READ_SIZE + 1];
  ssize_t readSize = pread(fd, buf, READ_SIZE, OFF_SIZE);
  if(readSize <= 0) {
    errorExit("pread error");
  }
  buf[readSize] = '\0';
  printf("pread result: %s \n", buf);
  off = lseek(fd, 0, SEEK_CUR);
  printf("current: %d\n", (int)off);

  return 0;
}