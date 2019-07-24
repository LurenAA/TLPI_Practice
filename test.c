#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  if(argc < 3 || argv[1] == "--help"){
    usageInfo("%s\n", argv[0]);
  }
  return 0;
}
