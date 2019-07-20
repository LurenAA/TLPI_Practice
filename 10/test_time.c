#include "TLPI_include.h"

int main(int argc, char* argv[])
{
  struct tms tms_buf1;
  clock_t tl2 = times(&tms_buf1);
  clock_t start_time = clock();
  struct timeval tim;
  if(gettimeofday(&tim, NULL) == -1)
    errorExit("error in gettimeofday in %s", argv[0]);
  printf("gettimeofday: tv_sec: %lu,\
   tv_usec: %ld\n", tim.tv_sec, tim.tv_usec);
  time_t tim_time = time(NULL);
  printf("time: %lu\n", (unsigned long)tim_time);
  printf("ctime: %s", ctime(&tim_time));
  struct tm* time_struc;
  // time_struc = gmtime(&tim_time);
  time_struc =localtime(&tim_time);
  printf("sec: %d, min: %d, hour: %d, mday: %d, \
    mon: %d, year: %d, wday: %d, yday:%d\n", time_struc->tm_sec,
     time_struc->tm_min,time_struc->tm_hour, time_struc->tm_mday,
     time_struc->tm_mon,  time_struc->tm_year, time_struc->tm_wday,
     time_struc->tm_yday);
  printf("asctime: %s", asctime(time_struc));
  char buf[100 + 1];
  strftime(buf, 100,"%c" , time_struc);
  printf("strftime: %s\n", buf);
  printf("clock time: %lf\n", ((double)(clock() - start_time))/((double)CLOCKS_PER_SEC));
  struct tms tms_buf;
  clock_t base = sysconf(_SC_CLK_TCK);
  clock_t tl = times(&tms_buf);
  printf("%lf\n", (double)(tl- tl2)/ tl);
  printf("%lf:%lf\n", (double) tms_buf.tms_utime , (double) tms_buf.tms_stime );
  return 0;
}