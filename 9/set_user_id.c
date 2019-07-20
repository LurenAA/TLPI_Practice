#include "TLPI_include.h"

int main(int argc, char* argv[])
{ 
  printf("uid: %d, euid:%d, gid: %d, egid: %d\n", 
    (int)getuid(), (int)geteuid(),(int)getgid(),(int)getegid());
  if(argc != 3 || argv[1] == "--help") {
    usageInfo("%s newUid newGid\n", argv[0]);
  }
  uid_t savedUid = geteuid();
  int res = setuid(get_long_dec(argv[1]));
  if(res == -1) {
    if(errno == EPERM) {
      errorExit("setuid: not a privilege user");
    }
    errorExit("%s setuid error", argv[0]);
  }
  printf("uid: %d, euid:%d, gid: %d, egid: %d\n", 
    (int)getuid(), (int)geteuid(),(int)getgid(),(int)getegid());
  // res = setgid(get_long_dec(argv[2]));
  // if(res == -1) {
  //   if(errno == EPERM) {
  //     errorExit("setgid: not a privilege user");
  //   }
  //   errorExit("%s setuid error", argv[0]);
  // }
  setuid(savedUid);
  printf("uid: %d, euid:%d, gid: %d, egid: %d\n", 
    (int)getuid(), (int)geteuid(),(int)getgid(),(int)getegid());
  return 0;
}