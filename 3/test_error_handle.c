#include <unistd.h>
#include <stdio.h>
#include "error_handle.h"

int main (int argc, char *argv[]) {
  // errorExit("%s, %s", "test1", "test2");
  usageInfo("%s not found\n", "sh");
  return 0;
}