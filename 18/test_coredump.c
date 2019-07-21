#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main()
{
  
  /*测试非法内存，产生core文件*/
  int *ptr = NULL;
  *ptr = 10; 
 
  return 0;
}