object = 27/exec.c
res = a.out
a.out:  a.o error_handle.o get_num.o
	g++ -g -o ${res} error_handle.o get_num.o a.o
vpath % lib

error_handle.o: error_handle.c error_handle.h
	g++ -c lib/error_handle.c -Ilib

get_num.o: get_num.c TLPI_include.h error_handle.h ename.c.inc get_num.h
	g++ -c lib/get_num.c -Ilib

a.o: ${object} lib/TLPI_include.h lib/error_handle.h lib/ename.c.inc \
 lib/get_num.h;	g++ -c ${object} -Ilib -o a.o -std=c99

 .PHONY: c

 c:
	rm error_handle.o get_num.o a.o