#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  if(argc != 2 || argv[1] == "--help") {
    usageInfo("%s file\n", argv[0]);
    exit(1);
  }
  struct spwd* wd = getspnam(argv[1]);
  if(wd == NULL) {
    if(errno == 0) {
      errorExit("not found");
    } 
    errorExit("%s error getspnam", argv[0]);
  }
  printf("%s:%s:%ld:%ld:%ld:%ld:%ld:%ld:%ld\n",
    wd->sp_namp,
    wd->sp_pwdp,
    wd->sp_lstchg,
    wd->sp_min,
    wd->sp_max,
    wd->sp_warn,
    wd->sp_inact,
    wd->sp_expire,
    wd->sp_flag
  );
  printf("crypt: %s\n", crypt("x99228899", "$6$ynLaEpBx$"));
  char pas[] = "input pass:";
  char* pasi = getpass(pas);
  printf("pass_input: %s\n", pasi);
  return 0;
}