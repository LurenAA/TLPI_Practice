object = 32/cancel.c
res = a.out
a.out:  a.o error_handle.o get_num.o
	g++ -o ${res} error_handle.o get_num.o a.o -pthread
vpath % lib

error_handle.o: error_handle.c error_handle.h
	g++ -c lib/error_handle.c -Ilib -g

get_num.o: get_num.c TLPI_include.h error_handle.h ename.c.inc get_num.h
	g++ -c lib/get_num.c -Ilib -g 

a.o: ${object} lib/TLPI_include.h lib/error_handle.h lib/ename.c.inc \
 lib/get_num.h;	g++ -c ${object} -Ilib -o a.o -std=c99 -g -pthread

 .PHONY: c

 c:
	rm error_handle.o get_num.o a.o
