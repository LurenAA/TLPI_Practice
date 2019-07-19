#include "TLPI_include.h"
extern char end;

int main(int argc, char* argv[])
{
  if(argc != 5 || argv[1] == "--help") {
    usageInfo("%s sizeOfBuf numberOfBuf \
    deleteBegin deleteEnd\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  int sizeOfBuf = (int)get_long_dec(argv[1]),
    numberOfBuf = (int)get_long_dec(argv[2]),
    deleteBegin = (int)get_long_dec(argv[3]),
    deleteEnd = (int)get_long_dec(argv[4]);

  printf("before program_break: %p\n", sbrk(0));
  char **buf = (char **)malloc(sizeof(char *) * numberOfBuf);
  for(int i = 0; i < numberOfBuf; ++i) {
    buf[i] = (char*)malloc(sizeof(char) * sizeOfBuf);
  }
  printf("after program_break: %p\n", sbrk(0));
  for(int i = deleteBegin; i < deleteEnd; ++i) {
    free(buf[i]);
  }
  printf("free program_break: %p\n", sbrk(0));
  //下面可以不释放
  for(int i = 0; i < deleteBegin; ++i) {
    free(buf[i]);
  }
  for(int i = deleteEnd; i < numberOfBuf; ++i) {
    free(buf[i]);
  }
  free(buf);

  return 0;
}