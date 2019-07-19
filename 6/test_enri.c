#include "TLPI_include.h"
extern char etext, edata, end;
extern char** environ;

int main(int argc, char* argv[])
{
  printf("etext: %x,edata: %x,end: %x\n", &etext, &edata, &end);
  printf("program name: %s(%s)\n",program_invocation_name, program_invocation_short_name);
  //test  /proc/self/cmdline
  int fd = open("/proc/self/cmdline", O_RDONLY);
  if(fd < 0) {
    errorExit("%s open error", argv[0]);
  }
  char buf[20 + 1];
  int num = 0;
  while((num = read(fd,buf,20)) > 0) {
    buf[num] = '\0';
    printf("cmd:%s\n", buf);
  }
  close(fd);
  // test environ
  // char **ep;
  // for(ep = environ; ep != NULL; ep++) {
  //   printf("environ: %s\n", *ep);
  // }
  //test getenv
  clearenv();
  char *str = (char*)malloc(30);
  strcpy(str, "abc=abc");
  putenv(str);
  printf("getenv: %s\n", getenv("abc"));
  setenv("abc", "def", true);
  printf("getenv: %s\n", getenv("abc"));
  unsetenv("abc");
  printf("getenv: %s\n", getenv("abc"));

  return 0;
}