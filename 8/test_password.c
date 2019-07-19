#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  pid_t id = getuid();
  // struct passwd* wd = getpwuid(id);
  struct passwd* wd = getpwnam("lurenaa");
  if(wd == NULL) {
    errorExit("%s error getpwuid", argv[0]);
  }
  printf("%s:%s:%d:%d:%s:%s:%s\n",
    wd->pw_name,
    wd->pw_passwd,
    (int)wd->pw_uid,
    (int)wd->pw_gid,
    wd->pw_gecos,
    wd->pw_dir,
    wd->pw_shell
  );
  // struct group* gr = getgrnam("lurenaa");
  gid_t gid = getgid();
  struct group* gr = getgrgid(gid);
  
  if(gr == NULL) {
    if(errno == 0) {
      errorExit("not found");
    } else {
      errorExit("error getgrnam");
    }
  }
  printf("%s:%s:%d", gr->gr_name, gr->gr_passwd, gr->gr_gid);
  while((*gr->gr_mem) != NULL) {
    printf("%s,", *gr->gr_mem);
    (*gr->gr_mem)++;
  }
  printf("\n");

  return 0;
}