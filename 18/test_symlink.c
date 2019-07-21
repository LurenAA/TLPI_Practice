#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  if(argc < 3 || argv[1] == "--help"){
    usageInfo("%s file1 link", argv[0]);
  }
  if(symlink(argv[1], argv[2]) == -1) {
    errorExit("%s error in symlink", argv[0]);
  }
  char buf[PATH_MAX + 1];
  ssize_t sizeRead;
  if((sizeRead = readlink(argv[2], buf, PATH_MAX)) <= 0) {
    errorExit("%s read link", argv[0]);
  }
  buf[sizeRead] = '\0';
  fprintf(stdout, "res: %s\n", buf);

  return 0;
}
