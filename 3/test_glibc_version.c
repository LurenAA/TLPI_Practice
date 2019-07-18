#include <unistd.h>
#include <stdio.h>

int main(void) {
  printf("version: %d : %d\n", __GLIBC__, __GLIBC_MINOR__);
}