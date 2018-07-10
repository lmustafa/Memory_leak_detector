make: main.o memcheck.o memcheck.h
	gcc -Wall -ansi -pedantic -I. main.o memcheck.o -o make
main.o: main.c
	gcc -Wall -ansi -pedantic -I. -o main.o main.c -c
memcheck.o: memcheck.c
	gcc -Wall -ansi -pedantic -I. -o memcheck.o memcheck.c -c
clean:
	rm *.o
