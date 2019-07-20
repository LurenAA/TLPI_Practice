#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  struct stat s,s1,s2,s3;
  if(stat(argv[1],&s) == -1) {
    errorExit("stat error");
  }
  stat(argv[2],&s2); 
  lstat(argv[2], &s3);
  printf("major: %ld, minor: %ld\n", major(s3.st_dev), minor(s3.st_dev));
  printf("islink: %d: %d\n", S_ISLNK(s3.st_mode), S_ISLNK(s2.st_mode));
  return 0;
}