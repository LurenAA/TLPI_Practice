#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  // if(argc < 3 || argv[1] == "--help"){
  //   usageInfo("%s file group\n");
  // }
  // struct group* newGinf = getgrnam(argv[2]);
  // if(newGinf == NULL) {
  //   errorExit("getgrnam error in %s", argv[0]);
  // }
  // gid_t newGid = newGinf->gr_gid;
  // if(chown(argv[1], -1, newGid) == -1) {
  //   errorExit("%s error chown", argv[0]);
  // }
  printf("%d\n", access(argv[1], F_OK));

  return 0;
}
