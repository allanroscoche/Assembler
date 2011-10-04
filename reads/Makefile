all: tests test1

test1: test1.c read.o
	gcc test1.c read.o -o test1

tests: tests.c read.o
	gcc tests.c read.o -o tests

read.o: read.c read.h
	gcc read.c -c -o read.o