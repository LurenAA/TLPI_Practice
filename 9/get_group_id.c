#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  gid_t garr[NGROUPS_MAX + 1];
  int tol = getgroups(NGROUPS_MAX, garr);
  for(int i = 0; i < tol; i++)
    printf("%d\n", garr[i]);
  return 0;
}