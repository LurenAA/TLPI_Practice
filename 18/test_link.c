#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  if(argc < 3 || argv[1] == "--help"){
    usageInfo("%s file1 link\n", argv[0]);
  }
  if(link(argv[1],argv[2]) == -1) {
    errorExit("%s error in link", argv[0]);
  }
  rename(argv[2], "renameLink");
  // unlink(argv[2]);
  return 0;
}
