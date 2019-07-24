#include "TLPI_include.h"

void overflowStack(int callnumber) {
  char a[100000];
  overflowStack(callnumber + 1);
}

// void sa_handler_h(int sig) {
void sa_handler_h(int sig, siginfo_t *s, void* ucontext){
  write(STDOUT_FILENO, "asd", 3);
  abort();
}

int main(int argc, char* argv[])
{
  stack_t ss;
  memset(&ss, '\0', sizeof(ss));
  ss.ss_sp = malloc(SIGSTKSZ);
  if(ss.ss_sp == NULL) {
    errorExit("error in malloc in %s", argv[0]);
  }
  ss.ss_size = SIGSTKSZ;
  if(sigaltstack(&ss, NULL) == -1) {
    errorExit("error in sigalstack ");
  }
  struct sigaction sigStruc;
  memset(&sigStruc, '\0', sizeof(sigStruc));
  // sigStruc.sa_handler = sa_handler_h;
  sigStruc.sa_sigaction = sa_handler_h;
  sigemptyset(&sigStruc.sa_mask);
  sigStruc.sa_flags = SA_ONSTACK | SA_SIGINFO;
  if(sigaction(SIGSEGV, &sigStruc, NULL) == -1) {
    errorExit("error in sigaction");
  }
  overflowStack(1);

  return 0;
}
