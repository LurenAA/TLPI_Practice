#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  if(argc < 2 || argv[1] == "--help"){
    usageInfo("%s file\n", argv[0]);
  }
  // struct stat fileStat;
  // struct utimbuf timesBuf;
  // if(stat(argv[1], &fileStat) == -1) {
  //   errorExit("%s stat error", argv[0]);
  // }
  // timesBuf.actime = fileStat.st_atim.tv_sec;
  // timesBuf.modtime = fileStat.st_atim.tv_sec;
  // if(utime(argv[0], &timesBuf) == -1) {
  //   errorExit("%s utime error", argv[0]);
  // }
  struct timespec times[2];
  times[0].tv_sec =  0;
  times[0].tv_nsec =  UTIME_OMIT;
  times[1].tv_sec =  0;
  times[1].tv_nsec =  UTIME_OMIT;
  if(utimensat(AT_FDCWD, argv[1], times, 0) == -1) {
    errorExit("%s utimensat error ", argv[0]);
  }

  return 0;
}