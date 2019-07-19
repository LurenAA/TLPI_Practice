#include "TLPI_include.h"

int main(int argc, char* argv[])
{
#define IOVS_NUMBERS 8
#define BASE_SIZE 13
  if(argc != 2 || argv[2] == "--help") {
    usageInfo("%s file1", argv[0]);
    exit(1);
  }
  struct iovec iovs[IOVS_NUMBERS];
  for(int i = 0; i < IOVS_NUMBERS; i++) {
    iovs[i].iov_base = malloc(sizeof(char) * BASE_SIZE);
    if(iovs[i].iov_base == NULL) {
      errorExit("malloc error in %s", argv[0]);
    }
    iovs[i].iov_len = BASE_SIZE;
  }
  int fd = open(argv[1], O_RDONLY);
  if(fd < 0) {
    errorExit("open error in %s", argv[0]);
  }
  ssize_t readNum = readv(fd, iovs, IOVS_NUMBERS);
  if(readNum < 0) {
    errorExit("readv error in %s", argv[0]);
  }
  printf("read number = %d\n", (int)readNum);
  printf("last one: %s \n", (readNum / BASE_SIZE == IOVS_NUMBERS) 
    ? "need to change value" :(char*)iovs[readNum / BASE_SIZE].iov_base);
  printf("offset: %d\n", (int)lseek(fd, 0, SEEK_CUR));
  close(fd);

  return EXIT_SUCCESS;
}