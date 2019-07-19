#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  struct passwd *wd;
  while((wd = getpwent()) != NULL) {
    printf("%s:%s:%d:%d:%s:%s:%s\n",
      wd->pw_name,
      wd->pw_passwd,
      (int)wd->pw_uid,
      (int)wd->pw_gid,
      wd->pw_gecos,
      wd->pw_dir,
      wd->pw_shell
    );
  }

  endpwent();
  return 0;
}