#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  // if(argc < 2 || argv[1] == "--help"){
  //   usageInfo("%s newDir", argv[0]);
  // }
  // mkdir(argv[1], S_IRWXU | S_IRWXG | S_IROTH);
  
  // DIR* dir = opendir(argv[1]);
  // int dirFd = dirfd(dir);
  // int dirFd2 = open(argv[1], O_DIRECTORY);
  // DIR* dir2 = fdopendir(dirFd2);
  // printf("descripor: %p:%d:%p:%d\n", dir, dirFd, dir2, dirFd2);
  // struct dirent* li;
  // while((li = readdir(dir2)) != NULL) {
  //   printf("i_num: %ld, name: %s\n", (long)li->d_ino, li->d_name);
  // }

  // char cwdBuf[PATH_MAX + 1];
  // printf("%s\n", getcwd(cwdBuf, PATH_MAX));

  // char desBuf[PATH_MAX + 1];
  char *p = strdup("/home/TLPI_practice/a.out");
  char * na = dirname(p);
  if(na == NULL) {
    errorExit("Err in dirname");
  }
  printf("%s\n", na);//realpath("../../", desBuf));

  return 0;
}
