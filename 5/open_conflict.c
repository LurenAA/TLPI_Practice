#include "TLPI_include.h"

int main(int argc, char *argv[]) {
  if(argc < 2) {
    usageInfo("%s file1", argv[0]);
    exit(1);
  }
  int key = open(argv[1], O_RDONLY);
  if(key < 0) {
    if(errno != ENOENT) {
      errorExit("%s", "errno is not ENOENT");
    } 
    if(argc > 2) {
      printf("started sleep\n");
      sleep(5);
    }
    key = open(argv[1], O_CREAT | O_RDONLY,  S_IRWXU | S_IRWXG | S_IROTH);
    if(key > 0) {
      printf("creat successful\n");
      close(key);
    } else {
      errorExit("%s", "creat error");
    }
  } else {
    printf("open file successful\n");
    close(key);
  }

  return 0;
}